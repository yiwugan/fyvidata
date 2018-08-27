#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "�̸赶��");
        set("usage/blade", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 200);
        set("learn_bonus", -100);
        set("practice_bonus", -5);
        set("practice_limit",190);
        set("black_white_ness", 10);
        set("skill_class", "legend");
        
        set("parry_msg", ({
        "$nʹ��һ�С�Ψ�жſ����������е�$v����$N����ָ��\n",
                "$n���̤ǰһ����һ�С��������ơ������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
                "$n���е�$vһ�������һƬ������һ�С��������ġ�������$N��ȫ��\n",
                "$n΢��һ�������е�$v����һ���⻡��һ�С���Ϊ���ʡ�����$N��ȫ��Χס��\n",
        }) ); 
        set("unarmed_parry_msg", ({
                "$nʹ��һ�С��������񡹣������е�$v����$N��\n",
                "$n���̤ǰ̤��һ�С�����¹���������е�$v����$N֮�ؾȡ�\n",
                "$n���е�$vһ����һ�С�ɽ����ߡ�������$N��\n",
                "$n���е�$v����һ�С����¹��ġ�����$N��ȫ��Χס��\n",
        }) );   
        action = ({
                ([      "action":               "$Nʹһ�С��ԾƵ��衹������$w���Ƶ���$n��$lնȥ��",
                        "damage":               100,
                 "force":               50,
                        "dodge":                70,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�䵶���£�$w����һ�С��������Ρ����¶�������$n��$l",
                        "damage":               400,
                 "force":               50,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����һת��һ�С�Ʃ�糯¶��$w�糯¶��˸��ն��$n��$l",
                        "damage":               90,
            "force":               50,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�趯$w��һ�С�ȥ�տ�ࡹ��$n��$lбб����һ��",
                 "force":               80,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����$wһ�Σ�һ�С������Կ���Ѹ�����׵�����$n��$l",
                 "force":               50,
                        "damage":               100,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�����������զչ��һ�С���˼������ֱ��$n$l",
                        "damage":               160,
                 "force":               50,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�Ʋ�����ʹһ�С����Խ��ǡ��������ն��$n��$l",
                        "damage":               80,
                 "force":               50,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 100 ){
        return notify_fail("�������������û�а취���̸赶����\n");
        }
    if( (string)me->query_skill_mapped("force")!= "qidaoforce"){
        return notify_fail("�̸赶�����������ѩ�ڹ���������\n");
        }
    if(!::valid_learn(me)){
        return 0;
    }
    return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 300 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "deisword" )
    if(me->query_skill("blade") > victim->query_skill("sword")) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n�򵶽���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("blade")) * 4;
    }
    return 0;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 10 ){
                return notify_fail("������������������������̸赶����\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        return 1;
}      
