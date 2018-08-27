 // eagle-claw.c
inherit SKILL;
#include <ansi.h> 
void setup() {
    set("name", "ӥצ��");
        set("usage/unarmed", 1);
        set("effective_level", 150);
        set("practice_bonus", -5);
        set("practice_damage", 30);
        set("learn_bonus", 10);
        set("skill_class", "fugui");
        set("parry_msg", ({
        "$nһ�С�������á����ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n��ȭ��Σ���ȭһ�С�ӭ����᡹���Ƶ�$N����������\n",
        "$n�Թ�Ϊ�أ�һ�С��γ��ɡ����ͻ�$N��$w������\n",
        "$nһ�С���ӥ��צ��������һ��$N��$w���֣���ƫ��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nһ�С�������á����Ƶ�$N��;���С�\n",
        "$n����������һ�С��γ��ɡ�����$N֮�ؾȡ�\n",
        "$n��ȭ���£���ȭ�Ա���һ�С�ӭ����᡹����$N���ڳ��⡣\n",
        "$n˫ȭ�����ʹ��һ�С���ӥ��צ����$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n", 
        }) );
        action = ({
                ([  "action" : "$N�εض��𣬰����һ�����һʽ����ӥϮ�á���Ѹ�͵�ץ��$n��$l",
                    "force" : 100,
                    "dodge" : 250,
                    "parry" : 250,
                    "damage_type" : "����"
                ]),
                ([  "action" : "$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צ£��$n��$l",
                    "force" : 120,
                    "dodge" : 200,
                    "parry" : 400,
                    "damage": 5,
                    "damage_type" : "����"
                ]),
                ([  "action" : "$Nһʽ���γ��ɡ���ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
                    "force" : 150,
                    "dodge" : 200,
               "parry" : 400,
                    "damage": 10,
                    "damage_type" : "����"
                ]),
                ([  "action" : "$N˫צ�����Ͼ٣�ʹһʽ��ӭ��������һ�����ֱ�Ϯ��$n����Ҹ����",
                    "force" : 190,
                    "dodge" : 150,
                    "parry" : 450,
                    "damage": 10,
                    "damage_type" : "����"
                ]),
                ([  "action" : "$Nȫ�������ǰ��һʽ��������צ������צͻ�������Ȱ�ץ��$n���ؿ�",
                    "force" : 150,
                    "dodge" : 500,
                    "parry" : 400,
                    "damage": 15,
                    "damage_type" : "����"
                ]),
                ([  "action" : "$N���ػ��У�һʽ������հ�ա�������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
                    "force" : 110,
                    "dodge" : 265,
                    "parry" : 365,
                    "damage": 20,
                    "damage_type" : "����"
                ]),
                ([  "action" : "$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ���ޱȵػ���$n",
                    "force" : 180,
                    "dodge" : 375,
                    "parry" : 575,
                    "damage": 25,
                    "damage_type" : "����"
                ]),
                ([  "action" : "$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n",
                    "force" : 170,
                    "dodge" : 800,
                    "parry" : 400,
                    "damage": 20,
                    "damage_type" : "����"
                ])
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������̫�����޷���ӥצ����\n");
        return 1;
} 
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 20) {
                return notify_fail("�������������ӥצ����\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}     
