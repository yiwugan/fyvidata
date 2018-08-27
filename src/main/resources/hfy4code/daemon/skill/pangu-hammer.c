 // cloudstaff.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "�̹ž�ʽ");
        set("usage/hammer", 1);
        set("usage/parry", 1);
        set("practice_damage", 60);
        set("effective_level", 200);
        set("learn_bonus", 10);
        set("practice_bonus", -30);
        set("black_white_ness", -10);
        set("skill_class", "yinshi");
        
        set("parry_msg", ({
        "$n����һ����һ�У۵����س������е�$v�͵�����$N��$w��\n",
                "$n����΢�٣����е�$vһ�У�Χ�����ԣݷ���$N�ıؾ�֮����\n",
                "$n���е�$v�������ϼ��ӣ�һ�У۶�����ݿĿ���$N���е�$w\n",
        }) ); 
        set("unarmed_parry_msg", ({
                "$nһ�У��ӹ������ݣ����е�$v��ƫ�����$N��̫����Ѩ��\n",
                "$n���е�$v�����ң�һ�Уۺ�ɨǧ���ݷ�ס��$N�Ĺ��ơ�\n",
                "$n�����������һ�У���ɳ�������е�$v����$N�ĺ��ԣ��Ƶ�$N��;���С�\n",
        }) );   
        action = ({
        ([      "action":               
"$N���ֻ���һ��ԲȦ�������е�$wһ�У������ķ�����$n��$l��ȥ��",
                "force":               700,
                "dodge":                600,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�����е�$w��һ�У�����ɽ�ӣݣ����е�$w��$n��$l����������¡�",
                "damage":               150,
                "dodge":                400,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�����ڿշ�����̩ɽѹ��֮ʽ���£����е�$w���ź������һ�У�ǧ��һ���ݻ���$n��$l��", 
                "damage":               70,
                "force" :               200,
                "dodge":                500,
                "parry":                700,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���е�$wһת��һ�Уۿ�籩��ݴ�����˷�����$n��$l",
                "damage":               40,
                "force" :               200,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ�����е�$w��һ�У����տ����ݻó�һƬ���⽣Ӱ������ʵʵ�Ļ���$n��$l",
                "force":               100,
                "damage" :              50,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
    if( (int)me->query("str") + (int)me->query("max_force") / 10 < 55 ){
        return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
    return 1;
} 
void skill_improved(object me)
{
    int s;
    s = me->query_skill("pangu-hammer", 1);
    if (s== 100)
        tell_object(me, HIW "������һ�����ƺ��Ӵ�����������ʲô��\n" NOR);
    if (s== 130)
        tell_object(me, HIW "������һ�����ƺ��Ӵ�����������ʲô��\n" NOR);
    if (s== 150) {
       tell_object(me,HIW " Ҳ������԰��ⴸ���ڻ��ͨ����ı޷���ȥ����\n"NOR);
       me->set("marks/hammerwhip",1);
      } 
} 
int practice_skill(object me)
{
        if (me->query_skill("pangu-hammer",1) > 100)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");       
        if ((int)me->query("force") < 20) {
                return notify_fail("�������������ϰ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 350 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "blade")
    if(victim->query_skill_mapped("blade") == "bat-blade"
     ||victim->query_skill_mapped("blade") == "ittouryu")
    if(me->query_skill("hammer") > victim->query_skill("blade")) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n$N�ϵл��ȣ�����ռ���Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N�����г���$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("hammer")) * 3;
    }
    return 0;
}     
