 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
        set("name", "�����ħ��������");
        set("usage/unarmed", 1);
        set("learn_bonus", 10);
        set("practice_bonus", 5);
        set("black_white_ness", -10);
        set("effective_level",160);
        set("skill_class", "bandit");
        set("parry_msg", ({
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
        }) );
        set("unarmed_parry_msg", ({
        "$nʩչ�������ħ�������ƣ����赭д�Ļ�����$N�Ĺ��ơ�\n",
        }) );
        action = ({
        ([      "action":               
"$N˫��һ��һ�С�ħ����١��ó�������Ӱ£��$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫�Ʒ׷ɣ�һ�С�ħ��ʳ⸡�ֱȡ$n��$l",
                "dodge":                10,
                "parry":                30,
                "damage":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ����˫�������Ƴ���һ�С�ħ����ء�ǿ�����Ʒ�ֱ��$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ħ���������еġ�ħ߱ɭɭ������ȫ��$n��$l������˫��֮��",
                "dodge":                10,
                "parry":                30,
                "damage":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����Ϊ����һ�С�Ǭ����ħ���������Ʒֿ�$n������Ҫ��",
                "dodge":                20,
                "parry":                30,
                "damage":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ᣬȫ�����һ�С�ħ�ߺ͹ѡ���˫���������",
                "dodge":                70,
                "parry":                10,
                "damage":                80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ߣ�һ�С�ħ�����ݡ���ɭɭ�Ʒ��޿ײ����ػ���$n��$l",
                "parry":                40,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ�������ħ���������еġ�����ħ��˫��Я���ħ��֮������$n��$l",
                "parry":                40,
                "force":                120,
                "damage" :              50,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
   }
    if( (int)me->query_skill("demon-force", 1) < 10) {
        return notify_fail("��������ħ�ķ�����㣬�޷��������ħ�������ơ�\n");
    }
    return 1;
}  
int practice_skill(object me)
{
                if(!::practice_skill(me)) {
                        return 0;
                }
        if( (int)me->query("force") < 5 ) {
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        me->add("force", -5);
        return 1;
}
void skill_improved(object me)
{
    int s;
    s = me->query_skill("demon-strike", 1);
    if (s== 150 && me->query("class")=="bandit") {
           me->set("once_menpai/bandit",1);
       } 
}   