 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "ˤ��");
        set("usage/unarmed", 1);
        set("learn_bonus", 10);
        set("practice_bonus", 20);
        set("black_white_ness", 5);
        set("skill_class", "xinjiang");
        set("parry_msg", ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N��$w�Ĺ�����Χ��\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N�Ĺ�����Χ��\n",
        }) );
        action = ({
        ([      "action":               
"$N˫��ǰ�죬�ƺ�Ҫץס$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫�ִ���$n�����������б���ƺ�Ҫ��$nˤ��",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�䲻�������ţ���ͼ��$n�赹�ڵ���",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ҽ���գ��γ�һƬ��Ӱ�����Ǽ���$n��$lһ���߳�����",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ס$n��$l����$n�ٹ�ͷ���������ºݺ�һˤ",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "����"
        ]),
        });
}        
