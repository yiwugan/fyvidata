 // mystsword.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "С������");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("effective_level", 70);
        set("learn_bonus", 40);
        set("practice_bonus", 20);
        set("black_white_ness", 30); 
        set("parry_msg", ({
        "���$n�����е�$v����$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        }) );   
        action = ({
        ([      "name":                 "ĺѩ��̾",
                "action":               "$Nʹһ�С�ĺѩ��̾��������$w���������ش���$n$l",
                "dodge":                -30,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����Ū��",
                "action":               "$N����һ�Σ�һ�С�����Ū�ѡ���$n$l�̳�һ��",
                "dodge":                -20,
                "damage":               80,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���Ȱ���",
                "action":               "$N�趯$w��һ�С����Ȱ�����Ю�������������$n��$l",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "޹�����",
                "action":               "$N����$wһ��Ȧת��ʹ����޹����硹�з�ֱ������$n��$l",
                "dodge":                -30,
                "damage":               100,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{ 
    if( (int)me->query_skill("mystforce",1) < 30 ){
        return notify_fail("��Ĳ����ķ���򻹲�����\n");
        }
    if( (int)me->query("max_force") < 100 ){
        return notify_fail("�������������û�а취��С��������\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 5 ){
        return notify_fail("�����������������û�а취��ϰС��������\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -5);
    write("�㰴����ѧ����һ��С��������\n");
    return 1;
}   
