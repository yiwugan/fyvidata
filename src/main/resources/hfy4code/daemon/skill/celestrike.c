 // celestrike.c
inherit SKILL; 
void setup() {
        set("name",                             "��а�Ʒ�");
        set("learn_bonus",                      10);
        set("practice_bonus",           5);
        set("black_white_ness",         -10);
        set("effective_level",  300);
        set("skill_class", "new");

        set("usage/unarmed",            1);
        set("parry_msg",                        ({
                        "$n����Ϊ����һ�С���Ѫ��ָ��������$N����$w���֡�\n",
                        "$n˫�ƽ���ʹ��һ�С�ͯ�Ӱ��١�����ž����һ����$N��$w����˫��֮�䡣\n",
                        "$n��һת��һ�С���������������$N����$w���֡�\n",
                        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
                })
        );
        set("unarmed_parry_msg",        ({
                        "$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
                        "$n����Ϊָ��һ�С���ָ˫�ɡ�����$N������ҪѨ��\n",
                        "$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
                })
        );
        
        action = ({
                        ([      "action":               
                        "$Nʹ��һ�С�������ʽ�������ƴ�������$n��$l",
                                "dodge":                -30,
                                "parry":                10,
                                "force":                200,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ��һ�С�������ʽ�������ƻ���Ϊʵ����$n��$l",
                                "dodge":                -10,
                                "parry":                -30,
                                "force":                170,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ����а�Ʒ���С����ʽ��������Ȱ�����$n��ǰ��һ������$n��$l",
                           "dodge":                -30,
                                "parry":                10,
                                "force":                150,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N˫��һ��ʹ����ѩ�������¡�����׼$n��$l�����ĳ�����",
                                "dodge":                10,
                                "parry":                -30,
                                "force":                260,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��鶯�巽�ġ�����$n$l",
                                "dodge":                -20,
                                "parry":                -30,
                                "force":                240,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ�����������Ƕϡ�������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                                "dodge":                -70,
                                "parry":                -10,
                                "force":                280,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N����������һ�С����������졹˫�Ʋ����Ƴ�",
                                "parry":                -40,
                                "force":                320,
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)){
                return 0;
        }
        if((int)me->query_skill("celestial", 1) < 20 ) {
                return notify_fail("�����а�񹦻���㣬�޷�����а�Ʒ���\n");
   }
        if((int)me->query("max_force") < 100 ) {
                return notify_fail("�������̫�����޷�����а�Ʒ���\n");
        }
        return 1;
} 
int practice_skill(object me) {
        if((int)me->query("force") < 5 ) {
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
}
