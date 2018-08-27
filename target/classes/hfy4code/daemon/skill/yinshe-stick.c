 // yinshe-stick.c
inherit SKILL; 
void setup() {
        set("name",                     "�����ȷ�");
        set("effective_level",          160);
        set("learn_bonus",              -20);
        set("practice_bonus",           -10);
        set("black_white_ness",         40);
        set("usage/staff",              2);
        set("usage/parry",              1);
        set("skill_class",              "quanli");
        set("parry_msg",                ({
                        "$nʹ��һ�С�®ɽ��������$v�ڿ�������$N��$w��\n",
                        "$n����$v��ڣ�һ�С�������צ����������$N��$w��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n����������ˣ�����$v�ն�����ס��$N�Ĺ��ơ�\n",
                        "$n����ֱͦͦ�˵��ڵأ�����$v����ɨ��$N��\n",
                        })
        );
        action = ({
                        ([      "action":               "$Nʹ��һ�С����߳��ա��������ڿն�������$w�Ҷ���������$n��$l�ݺ���ȥ��",
                                "damage":               40,
                                "dodge":                40,
                                "parry":                40,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]), 
                        ([      "action":               "$Nʹ��һ�С��������֡�������$w�������ѩ�����������֣���������$n��$l��",
                                "damage":               40,
                                "dodge":                20,
                                "parry":                60,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����$wһ��һ�С���·ɵء�����������$w������ֱָ$n��$l��",
                                "damage":               80,
                                "dodge":                10,
                                "parry":                40,
                                "post_action":  "bash_weapon",
                           "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����$w�ն���������������Х����һ�С���Х��������ֱ��$n��$l��ȥ��",
                                "damage":               200,
                                "dodge":                110,
                                "parry":                40,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����$wһ�Σ�����ȻΪ˫��һ�С�����˫�������ֱ�Ϯ��$n������Ҫ����",
                                "damage":               10,
                                "dodge":                100,
                                "parry":                200,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N������ת������$wһ�С�����������������$n��$lɨȥ��",
                                "damage":               20,
                                "dodge":                10,
                                "parry":                20,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N���δ�������$wһ�С�����ɫ˿����ֱ��ֱ�µش���$n��$l��",
                                "damage":               100,
                                "dodge":                10,
                                "parry":                20,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����һ�٣�����$wб��һ�С����߳�����������$n��$l��",
                                "damage":               50,
                                "dodge":                10,
                                "parry":                20,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����$w�趯�����������Ӱ��һ�С����ֵ�Ϻ�����Ӹ����Ƕ�ͬʱ����$n��$l��",
                                "damage":               50,
                                "dodge":                200,
                           "parry":                200,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$Nʹ��һ�С�������ɽ������Ծ������$w���϶��£���������$n��$l��",
                                "damage":               90,
                                "dodge":                30,
                                "parry":                50,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 35 ) {
                return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
}         
