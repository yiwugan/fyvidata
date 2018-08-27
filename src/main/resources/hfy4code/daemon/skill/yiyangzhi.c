 // yiyangzhi.c
inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name",                                     "һ��ָ");
        set("effective_level",          200);
        set("learn_bonus",              -100);
        set("practice_bonus",           -20);
        set("black_white_ness",         0);
        set("skill_class",              "shaolin");
        set("usage/unarmed",            1);
        set("parry_msg",                        ({
                        "$nһ�С����ĬĬ��������һָ��ָ��������Ϣ�ĵ�����$N��$w��\n",
                        "$n��ɫ���У�һ�С��������С���ٿ��һָ�ݳ�������$N��$w��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n�����ָ��̤��ͦ��һ�С���ֱ���С�������ָ������$N�������Ѩ��\n",
                        "$n����������ţ�һ�С����̽Կա���һָ��Χ��\n",
                        "$n����������Ӱ��һ�С�����ˮ�¡�����Գ�һָ��һ�����$N��\n",
                        })
        );
        action = ({
                        ([      "action":               
                        "$N������ת��ɣ�һ�С��������ء������б��һָ������$n$l",
                                "dodge":                130,
                                "parry":                130,
                                "force":                80,
                                "damage_type":  "����",
                                "weapon":               "����ʳָ",
                        ]),
                        ([      "action":               
                        "$N��͸ָ�⣬һ�С�ɳ����ǧ����������$n��$l��ȥ",
                                "dodge":                30,
                                "parry":                130,
                                "force":                90,
                                "damage_type":  "����",
                                "weapon":               "����ʳָ",
                        ]),
                        ([      "action":               
                   "$Nһ�С����ļ��ԡ���������ָ��ָ���ƿգ���$n��$l��ȥ",
                                "dodge":                30,
                                "parry":                180,
                                "force":                140,
                                "damage_type":  "����",
                                "weapon":               "һ��ָ��",
                        ]),
                        ([      "action":               
                        "ֻ��$N���������һ�С������������������ָ��ָָ������$n��$l",
                                "dodge":                30,
                                "parry":                100,
                                "force":                90,
                                "damage_type":  "����",
                                "weapon":               "������ָ",
                        ]),
        });
} 
int valid_learn(object me) {
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if((string)me->query("gender") != "����" ) {
                return notify_fail("һ��ָ��ֻ�����Ӳ��������书��\n");
        }
        if((int)me->query("max_force") < 250) {
                return notify_fail("�������������\n");
        }
        return 1;
}  
int practice_skill(object me) {
        if( (int)me->query("sen") < 30) {
                return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
        }
        if( (int)me->query("force") < 10) {
                return notify_fail("������������ˡ�\n");
        }
        me->receive_damage("sen", 30);
        me->add("force", -10);
        
   return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 150 ) return 0;
    if(victim->query_temp("weapon")==0) {
        if(victim->query_skill_mapped("unarmed") == "nine-moon-claw" 
                && me->query_skill("yiyangzhi",1)+60 > victim->query_skill("nine-moon-claw",1)) {
        switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N�������ָ����$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
        return random(me->query_skill("unarmed")) * 3;
        }
    }
    return 0;
}     
