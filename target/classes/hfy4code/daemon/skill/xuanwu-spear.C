 // yue-spear.c
//TIE@FY3
inherit SKILL; 
#include <ansi.h>
void setup() {
        set("name",                                     "������ʮǹ��");
        set("effective_level",          500);
        set("learn_bonus",              -300);
        set("practice_bonus",           -15);
        set("black_white_ness",         0);
        set("usage/spear",                      1);
        set("usage/parry",                      1);
        set("skill_class",                      "new");
        set("parry_msg",                        ({
                        "$n����һ����һ��"HIW"������˫���أ���ì��������"NOR"�����е�$v���¶��ϣ�������$N��$w��\n",
                        "$n���"HIM"��Ծ������췣��ڻ�ҫǰ캡�"NOR"�����е�$v��$N��$w�������⡣\n",
                        "$nʹ��"HIY"��·ת���񲢣����������᡹"NOR"����һɨ�����е�$v������$N��$w��\n",
                        "$nһ���֣�$v��"HIR"��ӵ츲���𣬷�������ӧ��"NOR"��$N��$w�������ȥ��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$nʹ��һ��"HIG"�����ƿ����ף���������Ӫ��"NOR"�������е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
                        "$nʹ��һ��"HIB"��Ū��Գ⮽��������Ǡ��ʡ�"NOR"����������ʧ��һ��ǹӰ֮�С�\n",
                        "$n������ת��$vֱ��$N��˫�֡�\n",
                        "$n�����е�$vһ�����������ǹӰ���ȵ�$N�������ˡ�\n",
                        })
        );
        
        action = ({
                        ([      "action":               
                                        "$N����$w��ת��"MAG"�����㱼�Ｒ����������᡹"NOR"��ֱ��$n��$l��ȥ",
                                "dodge":                32,
                                "parry":                20,
                                "force" :               40,
                                "damage":               9999,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N����$w�γ�����ǹӰ����Ȼһǹ"GRN"��ɭꪳ�����ܸ���һ����"NOR"��$n��$l��ȥ",
                                "dodge":                10,
                                "parry":                40,
                                "force":               15,
                                "damage":               9999,
                           "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nǹ��ͻת��һ��"RED"�����ó��������۽�ҹ������"NOR"�ر�����$n������ɨȥ",
                                "dodge":                20,
                                "parry":                30,
                                "force":               50,
                                "damage":               9999,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N��̤����ǰ����������$wƽƽ�ݳ���ǹӰ֮������һ��"BLU"��Ω��������������ն������"NOR"ֱȡ$n��$l",
                                "force":                30,
                                "dodge":                20,
                                "parry":                30,
                                "damage":               9999,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N����$w�����㣬"YEL"�����ݷ���ǣ���ԭ��ϴ����"NOR"ʹ������$nɨ��һ��ǹӰ",
                                "dodge":                20,
                                "parry":                20,
                                "force":               30,
                                "damage":               9999,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N����ǹ�����Ҵ��壬"GRN"���׷���˪�䣬�������վ���"NOR"�Ծ������Ʒ�����$n��$l��ȥ",
                                "dodge":                56,
                                "parry":                13,
                                "force":               10,
                                "damage":               9999,
                                "damage_type":  "����"
                        ]),
        });
} 
/*int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 30) {
                return notify_fail("�������������û�а취��������ƽǹ����\n");
        }
        
   return 1;
} 
int practice_skill(object me) {
        
        if (me->query_skill("yue-spear",1) > 120)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        if((int)me->query("force") <10 ) {
                return notify_fail("�������������û�а취��ϰ������ƽǹ����\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        write("�㰴����ѧ����һ��������ƽǹ����\n");
        return 1;
} */ 