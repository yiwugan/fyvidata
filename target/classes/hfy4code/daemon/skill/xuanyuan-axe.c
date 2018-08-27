 inherit SKILL;
#include <ansi.h> 
void setup(){
        set("name", "��ԯ����");
        set("usage/axe", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 200);
        set("learn_bonus", 0);
        set("practice_bonus", -5);
        set("practice_limit",120);
        set("black_white_ness", 0);
        set("skill_class", "knight");
        
        set("parry_msg", ({
        "���$nһ�С�����Ʈ翡����Ӷ�����$v����$N��$w��\n",
        "���$n����$vһ�֣�һ�С���ת���̡���б��$N��$w��\n",
        "���$n����$v�ն���ɣ�һ�С�����ü��������$N��$w��\n",
        "���$n����$v������ת��һ�С����񹤡�����ɨ$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n���е�$v�趯��ɣ�һ�С������ӡ�����ס��$N�Ĺ��ơ�\n",
        "$n��Ӱ�ζ���һ�С�����񺿡�������$N�����̡�\n",
        "$n����һ����һ�С���ħͬ�塹�����$N�Ĺ��ơ�\n",
        "$n���е�$v���϶��£�һ�С���ڤ��Ӱ��������$N��Ҫ����\n",
        }) );   
        action = ({
        ([      "action":               
"$N����$w�趯���Ų�һ����һ�С��������ϡ�������$w�����ǰ�ֱ��$n��$l��",
                "damage":               210,
                "dodge":                210,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������ء��羪��һƲ����$n���޾�Ѷ��һ˲��$w������$n����ǰ��",
                "damage":               210,
                "dodge":                210,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�����ݰ���ת��ͣ��һ�С����������ֱȡ$n�ĸ���Ҫ����",
                "damage":               200,
                "dodge":                140,
                "parry":                100,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wǣ���������������һ�С����°����������а���$n$l��ȥ��",
                "damage":               150,
                "dodge":                100,
                "parry":                100,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�ݷ����������㣬һ�С��ط����򡹣�ͻȻ������һ�ɺ�����$N�ĸ���͸����",
                "damage":               250,
                "dodge":                210,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"ͻȻ���ݷ�ռ䱻�Ϳհ㣬$N����$w����һ���̳���һʽ�������ס�ʹ$n���������У�", 
                "damage":               210,
                "dodge":                210,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        });
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)){
           return 0;
        }
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 ){
            return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if( (int)me->query("force") < 15 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -15);
        return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 350 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "spear")
    if(victim->query_skill_mapped("spear") == "xuezhan-spear")
    if(me->query_skill("xuanyuan-axe",1) > victim->query_skill("xuezhan-spear",1)) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N��ʽ�������磬$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("axe")) * 4;
    }
    return 0;
}   

void skill_improved(object me)
{
    int s;
    s = me->query_skill("xuanyuan-axe",1);
    if (s== 200 && me->query("class")=="knight") {
       tell_object(me,HIW "���������еĸ�ͷ������ӿ��һ��Ī������ĸо���\n"NOR);
       tell_object(me,HIW "Ҫ����������ϰ��ԯ�������ض������ش��ͻ�ƣ�\n"NOR);
       } 
    if (s== 210 && me->query("class")=="knight") {
       tell_object(me,HIW "��ϲ�㣬�����ԯ�����Ѿ��Ƿ��켫�ˣ�\n"NOR);
       }
}      

