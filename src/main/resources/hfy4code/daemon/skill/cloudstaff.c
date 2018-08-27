 // cloudstaff.c
inherit SKILL; 
void setup() {
        set("name",                     "�����ȷ�");
        set("learn_bonus",              -100);
        set("practice_bonus",           -5);
        set("black_white_ness",         -10);
        set("effective_level",          200);
        set("usage/staff",                      1);
        set("usage/parry",                      1);
        set("practice_damage",          30);
        set("practice_limit",170);
        set("skill_class",                      "bonze");       
        set("parry_msg",                        ({
                        "���$n�����е�$v����$N��$w��\n",
                        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
                        })
        ); 
        set("unarmed_parry_msg",        ({
                        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
                        })
        );
        action = ({
                        ([      "action":               
                                        "$Nʹһ�С����է�֡�������$wɨ��$n���̣�",
                                "damage":               40,
                                "dodge":                80,
                                "parry":                80,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N����$w��һ�С�������硹����$n$l��",
                                "damage":               40,
                                "dodge":                70,
                                "parry":                90,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":           
                                   "$N�������$w��ʹ��������д�⡹����$n$l��",
                                "damage":               40,
                                "dodge":                50,
                                "parry":                70,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nʹ��һ�С��������ơ���$wһͦײ��$n$l��",
                                "damage":               40,
                                "dodge":                50,
                                "parry":                80,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        
        if((int)me->query("str") + (int)me->query("max_force") / 10 < 35) {
                return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
}  
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 20) {
                return notify_fail("������������������ȷ���\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}
