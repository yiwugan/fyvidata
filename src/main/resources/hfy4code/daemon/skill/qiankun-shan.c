 //TIE@FY3
// qiusheng-blade.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "Ǭ��������");
        set("usage/blade", 1);
        set("usage/parry", 1);
        set("practice_damage", 40);
        set("effective_level", 200);
        set("skill_class", "new");
        set("parry_msg", ({
        "$nʹ��һ�С��һ������һ��֡������е�$vɢ��˿˿��������$N��$w��\n",
                "$n����$v���������һ�С��һ������һ��ɡ�����Ӱ��ͻȻ����һ�ƹ�â�Ӳ��滮��$N֮�ؾȡ�\n",
                "$n����΢�٣����е�$v����һ�����⣬һ�С��һ�������������������$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
                "$nʹ��һ�С���ժ�һ�����Ǯ�������е�$v����������$N�Ĺ����沨��ɢ��\n",
                "$n���μ��ˣ�����$v���·��裬һ�С�����ֻ�ڻ�ǰ��������ס$N����ʽ��\n",
                "$n���е�$v�����䵶����һ�С������������ߡ����������ࡣ\n",
        }) );   
        action = ({
                ([      "action":               "$Nʹһ�С���������ո��ա�������$wһ�ڣ����μ�����ɣ����˺�һ������$n��$l��",
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N$w�����������⣬һ�С����仨���긴�꡹����������$n��$l��",
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����$w����������ˮ��һ�С���Ը�������Ƽ䡹��бб����$n��$l",
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����$w���⼤����һ�С���Ը�Ϲ�����ǰ����ն��$n��",
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����$w���裬�������Ŵشأ�һ�С��������������¡���ƮƮ������$n��ȥ",
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����$w����ɭȻ��һ�С���յ��֦��ʿԵ��ֱ��$n$l",
                        "damage_type":  "����"
                ]),
           ([      "action":               "$Nʹһ�С��������߱���ʿ��������$w�ڶ����������ն��$n��$l",
                        "damage_type":  "����"
                ]),
        });
}
/*int valid_learn(object me)
{
        if( (string)me->query("gender") != "����" ){
            return notify_fail("����������ֻ�����Բ��������书��\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} */
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 50 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "qiuzhi-sword" )
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
    return random(me->query_skill("blade")) * 10;
    }
    return 0;
}        
