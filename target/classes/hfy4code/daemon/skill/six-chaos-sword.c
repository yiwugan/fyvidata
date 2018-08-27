 // six-chaos-sword.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "����׷�꽣��");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("black_white_ness", 400);
        set("effective_level", 400);
        set("learn_bonus", 400);
        set("practice_bonus", 400);

        set("parry_msg", ({
        "$n���˷������������죬һ�С������ޱߡ������е�$v�ݺݿĿ���$N��$w��\n",
                "$n�ؽ����أ�һ�С����Ʈ�㡹����ס��$N��$w��\n",
                "$nһ�С�Ⱥħ���衹�����е�$v����ǧ�ٰѣ���ס��ȫ��\n",
                "$n���е�$v�������£�������$N��$w�������Ρ�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nʹ��һ�С�����ħ�ϡ�������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�\n",
                "$nһ�����е�$v��ʹ��һ�С�����ħ�ݡ������е�$v��ס��ȫ��\n",
                "$n��$v������һ�̣�$v�����������պ�ֱ��$N��˫�ۡ�\n",
                "$n�ٽ�������һ�������ӽ���͸�����ƿ���$N��\n",
        }) ); 
        action = ({
                ([      "name":                 "Ⱥħ����",
                        "action":               "$Nʹһ�С�Ⱥħ���衹������$w�����������$n��$l��������",
                        "dodge":                50,
                        "damage":               170,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "�������",
                        "action":               "$N����һת��һ�С��������$wն��$n��$l",
                        "dodge":                -50,
                        "damage":               20,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "�ٹ�ҹ��",
                        "action":               "$N�趯$w��һ�С��ٹ�ҹ�С�Ю�������������$n��$l",
                        "dodge":                -40,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "������·",
                        "action":               "$N����$wһ����ʹ����������·����$n��$l�̳�һ��",
                   "dodge":                -40,
                        "damage":               40,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��Ӱ����",
                        "action":               "$N����$w���Ⱪ����һ�С���Ӱ��������$n$l��ȥ",
                        "dodge":                -60,
                        "damage":               20,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��ع�",
                        "action":               "$N����$wֱָ$n$l��һ�С���ع����������˽�����ȥ",
                        "dodge":                -20,
                        "damage":               50,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_force") < 100 ){
                return notify_fail("�������������û�а취������׷�꽣��\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
}
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ){
                return notify_fail("�����������������û�а취��ϰ����׷�꽣��\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        write("�㰴����ѧ����һ������׷�꽣����\n");
        return 1;
} 
void skill_improved(object me)
{
        if( (int)me->query_skill("six-chaos-sword", 1)  % 10 == 0 ) {
                tell_object(me,RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
                me->add("bellicosity", 1000);
        } else
                me->add("bellicosity", 100);
} 
