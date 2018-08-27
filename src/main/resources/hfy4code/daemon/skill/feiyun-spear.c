 // yue-spear.c
//TIE@FY3
inherit SKILL; 
void setup() {
        set("name",                                     "������ǹ");
        set("effective_level",          350);
        set("learn_bonus",              -1000);
        set("practice_bonus",           -1500);
        set("black_white_ness",         0);
        set("usage/spear",                      1);
        set("usage/parry",                      1);
        set("skill_class",                      "new");
        set("parry_msg",                        ({
                        "$nһʽ�����֪���������е�$v���¶��ϣ�������$N��$w��\n",
                        "��һ�С��������ơ���$n�������е�$v����ܲ�͸�磬��$N��$w�������⡣\n",
                        "$n���ݰ벽��һʽ�������ƹ�����е�$v����������գ�������$N��$w��\n",
                        "$n���е�$vһ����ǹ������һʽ�����Ƽ��ա���$N��$w�������ȥ��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$nʹ��һ�С����Ʊ�á��������е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
                        "$nʹ��һ�С����Ƽʻ᡹����������ʧ��һ��ǹӰ֮�С�\n",
                        "$n����ת��һ�С���ʯ���ơ�$vֱ��$N��˫�֡�\n",
                        "$n�����е�$vһ����һ�С�������ˮ���������ǹӰ���ȵ�$N�������ˡ�\n",
                        })
        );
        
        action = ({
                        ([      "action":               
                                        "$Nһ�С��������ơ�������$w��ת��ǹ��\n�������ϣ�ֱ��$n��$l��ȥ",
                                "dodge":                32,
                                "parry":                20,
                                "force" :               40,
                                "damage":               99,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nһ�С���ɽ���꡹������$w�γ�����\nǹӰ����Ȼһǹ��$n��$l��ȥ",
                                "dodge":                10,
                                "parry":                40,
                                "force":               15,
                                "damage":               199,                                 
                           "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nһ�С�����Ұ�ס���ǹ��ͻת����$n������ɨȥ",
                                "dodge":                20,
                                "parry":                30,
                                "force":               50,
                                "damage":               299,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nһ����Х��һ�С�������ɢ������̤����ǰ����������$w\nƽƽ�ݳ���ֱȡ$n��$l",
                                "force":                30,
                                "dodge":                20,
                                "parry":                30,
                                "damage":               499,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nһ�С�����֮�𡹣�����$w�����㣬��ؽ�������\n��$nɨ��һ��ǹӰ",
                                "dodge":                20,
                                "parry":                20,
                                "force":               30,
                                "damage":               999,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nһ�С����Ƴ�¶�������г�ǹ������ң����Ʋ�����ļȻ��\n����$n��$l��ȥ",
                                "dodge":                56,
                                "parry":                13,
                                "force":               10,
                                "damage":               9999,
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 30) {
                return notify_fail("�������������û�а취��������ǹǹ����\n");
        }
        
   return 1;
} 
int practice_skill(object me) {
        
        if (me->query_skill("yue-spear",1) > 120)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        if((int)me->query("force") <10 ) {
                return notify_fail("�������������û�а취��ϰ������ǹǹ����\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        write("�㰴����ѧ����һ�������ǹǹ����\n");
        return 1;
}  
