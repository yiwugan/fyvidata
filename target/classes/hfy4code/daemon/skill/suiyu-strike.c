 //ximen@glqx.net
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "����ȭ��");
        set("usage/unarmed", 1);
        set("skill_class", "tieflag");
        set("effective_level", 230);
        set("learn_bonus", -10);
        set("level",         3);
        set("practice_bonus", 10);
        set("black_white_ness", 20);
        
        set("parry_msg", ({
        "$n˫ȭһ����$N�����������Ρ�\n",
        "$n���ط�����һȭֱ��Ҫ����$N���ȳ��ع��ơ�\n",
        "$nһȭ����һȭ��ȭ�羹�������ذ�$N�Ĺ��ƱƳ�Ȧ�⡣\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nȭ��չ�����������صõ�ˮ��©��\n",
        "$n���մ�������ȭ������$N�Ľ���·��ȫ��ȫ����ס��\n",
        }) );   
        action = ({ 
                ([      "action":               "$N̤����ǰ��ȭͷ��������һ��ֱ��$n��Ҫ��", 
                        "dodge":                 50, 
                        "parry":                250, 
                        "force" :               100, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N����������ȭͷ�����������籩�������ֱ��$n��ȥ", 
                        "dodge":                250, 
                        "force" :               150, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N����ܿ�$n�Ĺ��ƣ���ȭ���»�������ȭֱ��$n����", 
                        "dodge":                150, 
                        "parry":                100, 
                        "force" :               250, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$nֻ����ȭ��ӭ������������$N��ȭͷ������ǰ��С���", 
                        "dodge":                100, 
                        "force" :               300, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$Nת������ȭȫ������$n��̫��Ѩ", 
                        "dodge":                150, 
                        "parry":                100, 
                        "force" :               250, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N����Ʈ�����۽�$n����ͻȻ˫ȭȫ������", 
                        "dodge":                150, 
                        "parry":                100, 
                        "force":                250, 
                        "damage_type":  "����" 
                ]), 
        }); 
}
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 500 )
            return notify_fail("�������������û�а취������ȭ����\n");
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 5 ) {
       return notify_fail("�������������û�а취��ϰ����ȭ����\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -5);
    write("�㰴����ѧ����һ������ȭ����\n");
    return 1;
} 
