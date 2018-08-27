#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "�廢���ŵ�");
        set("usage/blade", 1);
        set("usage/parry", 1);
        set("effective_level", 250);
        set("practice_bonus", -5);
        set("black_white_ness", -20);
        set("skill_class", "new");
        set("parry_msg", ({
        "$n���һ��������$v���������ǿ�ҵĵ���Ƶ�$N����������\n",
        "$n���е�$v�ڿ��лó�������Ӱ��$N��������ʵ��ֻ���˺�������ת��Ϊ�ء�\n",
        "$n����˫�ۣ�$v�������԰�ֱ��$N��$w���ֱۿ�ȥ���ŵ�$N��ס���ˡ�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n���е�$v�󿪴��أ������$N����ʽ������ס��\n",
        "$n����һ������ǡ�ð�$N���е�·�߷���������֪�Ѷ��ˡ�\n",
        }) );   
        action = ({
                ([      "action":               
                "$N���е�$wһ�С������������滯��һ���⻪����$n��$l",
                        "parry":                260,
                        "damage":               200,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$Nʹ��һ�С��������$w�總��֮�������$n��$l",
                	"parry":                380,
                        "damage":               100,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$N̤����ǰ��һ�С��˾�����$wֱն��$n��$l",
                        "parry":                160,
                        "damage":               210,
                        "damage_type":  "����"
                ]),
                ([      "action":               
               "$N�ζ����е�$w��һ�С��������������ڿ���������һ��ֱ��$n��Ҫ����ȥ",
                        "parry":                280,
                        "damage":               620,
                        "damage_type":  "����"
                ]),
        });
}

int practice_skill(object me)
{
        if (me->query_skill("duanmen-blade",1) > 100)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");       
        if ((int)me->query("force") < 20) {
                return notify_fail("�������������ϰ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}   
