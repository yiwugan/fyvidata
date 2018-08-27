 // yuping-dagger.c
inherit SKILL; 
void setup() {
        set("name",                                     "��ƽ�̱���");
        set("usage/dagger",                     1);
        set("usage/parry",                      1);
        set("practice_damage",          40);
        set("effective_level",          150);
        set("learn_bonus",                      -20);
        set("practice_bonus",           -10);
        set("black_white_ness",         30);
        set("skill_class",                      "quanli");
        set("unarmed_parry_msg",                        ({
                        "$n����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ������$N��ȫ��ӿȥ��\n",
                        "$nʹ��һ�С��׷��ȡ�����ۻ��գ�����������ֱ��$N��$l,�ܵ�$N�������ˡ�\n",            
                        })
        ); 
        action = ({
                        ([      "action":       "$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ",
                                "damage":               70,
                                "dodge":                70,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
                                "damage":               40,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
                                "damage":               20,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�",
                                "damage":               70,
                                "damage_type":  "����"
                        ]),
                        ([      "action":        "$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n",
                                "damage":               30,
                           "damage_type":  "����"
                        ]),
                        ([      "action":               "$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
                                "damage":               50,
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        object ob;
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query_skill("force", 1) < 100) {
                return notify_fail("����ڹ��ķ�������û�а취����ƽ�̱��С�\n");
        }
        
        if((string)me->query_skill_mapped("force")!= "wuchenforce") {
                return notify_fail("��ƽ�̱��б�������޳��ķ���������\n");
        }
        return 1;
}
