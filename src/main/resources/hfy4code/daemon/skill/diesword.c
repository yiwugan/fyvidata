#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name", "����������");
        set("effective_level",  230);
        set("learn_bonus", -100);
        set("practice_bonus", -50);
        set("practice_limit",170);
        set("black_white_ness", 20);
        set("skill_class", "legend");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("parry_msg",  ({
        "$nʹ��һ�С�������������е�$v������$N��$w��\n",
        "$nʹ������������ʡ�����$N��$w�������⡣\n",
        "$nʹ��һ�С�ǿ�ֻ���ζ�������е�$v����������գ�������$N��$w��\n",
        "$n���е�$vһ����һ�С��ԾƵ��衹����$N��$w��������ȥ��\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬һ�С����ǿ��Ϊ����ס��$N�Ĺ��ơ�\n",
        "$n����һ�С����������ޡ�����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С��м���ɫ�ԡ���$vֱ��$N��˫�֡�\n",
        "$n�����е�$vһ����һ�С��Ѿ��ִ��������ȵ�$N�������ˡ�\n",
        }) );
        action = ({
                ([              "action":
        "$Nʹһ�С�����Σ¥��ϸϸ��������$w�����һ�����$n��$l",
                "dodge":                20,
                                "force" :               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
        "$Nʹ�����������еġ���ɫ�̹���������������հ�����$n��$l",
                "dodge":                20,
                "force":               200,
                "damage_type":  "����"
        ]),
        ([      "action":               
                "$Nһ�С�����˭��ƾ���⡹������$wĬĬ������$n��$l",
                "dodge":                30,
                "force":               50,
                "damage_type":  "����"
        ]),             
        ([      "action":               
                "$N����$wһʽ��������ͼһ����׼$n��$lһ���̳��߽�",
                "force":                90,
                "damage_type":  "����"
        ]),
        ([      "action":               
                "$N��$wƾ��һָ��һ�С��´������ղ��ڡ�����$n��$l",
                "dodge":                20,
         "force":               300,
                "damage_type":  "����"
        ]),
        ([      "action":               
                "$N����$w����һ�֣�ʹһ�С�Ϊ���������㲡����ֶ�׼$n$lһ����ȥ",
                "dodge":                20,
                "force":               100,
                "damage_type":  "����"
        ]),
        });
}        
int valid_learn(object me)
{
                if(!::valid_learn(me)) {
                        return 0;
                }
        if((int)me->query("max_force") < 50 ) {
                return notify_fail("�������������û�а취��������������\n");
                } 
        return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 10) {
        return notify_fail("�����������������û�а취��ϰ������������\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -10);
    write("�㰴����ѧ����һ�������������\n");
    return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob;
        if( random(damage_bonus) < 300 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "blade")
        if(victim->query_skill_mapped("blade") == "shortsong-blade" )
        if(me->query_skill("sword") > victim->query_skill("blade")) {
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
        return random(me->query_skill("sword")) * 4;
        }
        return 0;
}  
