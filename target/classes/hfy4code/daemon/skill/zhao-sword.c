 // zhao-sword.c ��չ÷����
inherit SKILL; 
void setup() {
        set("name",                                     "��չ÷����");
        set("usage/sword",                      1);
        set("usage/parry",                      1);
        set("practice_damage",          40);
        set("effective_level",          150);
        set("skill_class",                      "quanli");
        set("unarmed_parry_msg",        ({
                        "$nʹ��һ�С���÷��Թ���������е�$v����$N����ָ��\n",
                        "$n���̤ǰһ����һ�С�÷��ѩ�串��ƻ�������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
                        "$n���е�$vһ�������һƬ������һ�С�������÷��ѩ�ҡ�������$N��ȫ��\n",
                        "$n΢��һ�������е�$v����һ���⻡��һ�С�����������ŪӰ������$N��ȫ��Χס��\n",
                        "$nʹ��һ�С���������ֱ���ۡ��������е�$v����$N��\n",
                        "$n���̤ǰ̤��һ�С���ɽһ�����ı̡������е�$v����$N֮�ؾȡ�\n",
                        "$n���е�$vһ����һ�С�����δ�϶��Ⱦ���������$N��\n",
                        "$n���е�$v����һ�С�����Ц�졹����$N��ȫ��Χס��\n",
                        })
        );
        action = ({
                ([      "action":"\n$Nһʽ��÷�����͡�������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
                "force" : 160,
                "dodge" : 5,
                "damage": 30,
                "damage_type":  "����"
                ]),
                ([      "action":"$N��������Ծ��һʽ��÷�����֦ͷ����������ˮ��һкǧ�����$nȫ��",
                "force" : 180,
                "dodge" : 10,
                "damage": 35,
                "damage_type":  "����"
                ]),
                ([      "action":"$N����$wһ����һʽ��������ˬ����������Ϣ�ػ���$n��$l",
                "force" : 250,
                "dodge" : 15,
                "damage": 40,
                "damage_type":  "����"
                ]),
                ([      "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ����Թ���ࡹ����$n���ʺ�",
           "force" : 320,
                "dodge" : 15,
                "damage": 55,
                "damage_type":  "����"
                ]),
                ([      "action":"\n$N����һ���εض���һʽ����ѩ���䡹��$w�ó������Ӱ����$n����Χס",
                "force" : 420,
                "dodge" : 15,
                "damage": 70,
                "damage_type":  "����"
                ]),
                ([      "action":"$N�������Ʈ�䣬һʽ�����￴����������$wƽָ����������$n����",
                "force" : 450,
                "dodge" : 15,
                "damage": 80,
                "damage_type":  "����"
                ]),
                ([      "action" : "$Nļ��ʹһ�С������绪������ʱ�����м���Ѫ������$nȫ��",
                "force" : 500,
                "dodge" : 25,
                "damage": 100,
                "damage_type":  "����"
                ]),
        });
} 
int valid_learn(object me) {
        object ob;
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("max_force") < 100) {
                return notify_fail("�������������\n");
        }
        if ((int)me->query_skill("wuchenforce", 1) < 20) {
                return notify_fail("����޳��ķ����̫ǳ��\n");
        }
        if ((int)me->query_skill("force", 1) < 20) {
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");
        }
   return 1;
}
