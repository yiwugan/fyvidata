 //duanhun-biao.c
inherit SKILL;
#include <ansi.h>
void setup() {
       set("name", "�ɻ�׷����");
        set("usage/throwing", 1);
        set("skill_class", "new");
        set("effective_level", 140);
        set("learn_bonus", -100);
        set("practice_bonus", -50);
        set("black_white_ness", 10);
        action = ({
        ([      "action":               
"$N�粻̧�ֲ�����ͻȻ$w��һ������������$n��$l",
                "dodge":                30,
                "damage":               80,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫������̽����$w���ż�����ƿ���ֱ��$n��$l",
                "dodge":                -50,
                "damage":               100,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ˦��$w��һ�����벻���ĽǶ�����$n��$l",
                "dodge":                10,
                "damage":               50,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ע������$w����ɢ�����̶��ط�$n",
                "dodge":                -20,
                "post_action":  "throw_weapon",
                "damage":               200,
                "damage_type":  "����"
        ]),
        });
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 300 ) {
                return notify_fail("�������������û�а취ϰ�÷ɻ��ϻ��ڡ�\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 500 ) {
        return notify_fail("�������������û�а취��ϰ�ɻ��ϻ��ڡ�\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -10);
    write("�㽫�ɻ��ϻ���������һ�顣\n");
    return 1;
}    
