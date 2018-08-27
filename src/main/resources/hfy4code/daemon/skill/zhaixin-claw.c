 // nine-moon-claw.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "ժ����");
        set("usage/unarmed", 1);
        set("effective_level", 190);
        set("skill_class", "huashan");
        set("learn_bonus", -400);
        set("practice_bonus", 5);
        set("practice_limit",100);
        set("black_white_ness", -10);
        set("unarmed_parry_msg", ({
        "$nָ�ⷢ��˿˿����ץ��$N����$N��æ����ܿ���\n",
                "$n����һ��������������$Nֻ������һ�գ���ʽ��ƫ�� \n",
        }) );
        action = ({
        ([      "action":               
"$N����ֱץ������б�ӣ�һ�С�ժ�����¡�ץ��$n$l",
                "dodge":                100,
                "parry":                140,
                "force":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nһ�С�������÷�������ֺ��أ����ֳ�צ��ֱ��$n$l",
                "dodge":                150,
                "parry":                100,
                "force":                170,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nʹ�������������������������䣬צӰɭɭ����$n$l",
                "dodge":                50,
                "parry":                120,
                "force":                140,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N�ز�б�����ֳ�צ����һ��Բ����һʽ�����ӷ�������$n$l",
                "dodge":                310,
                "parry":                200,
                "force":                290,
                "damage_type":  "ץ��"
        ]),
        });
}
int valid_learn(object me)
{
    if( me->query("bellicosity")>50)
        return notify_fail("��������������޷������������ʦ���Ľ̵���\n");  
    return ::valid_learn(me);
} 
int practice_skill(object me)
{
    if( (int)me->query("force") < 5 ){
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
    }
    if( (int)me->query("max_force") < 100 ){
        return notify_fail("�������̫�����޷���ժ��צ��\n");
        }    
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -5);
    return 1;
}    
