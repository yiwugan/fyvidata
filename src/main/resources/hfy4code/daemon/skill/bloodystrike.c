 // bloodystrike.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL; 
void setup() {
        set("name",                             "���ڴ���ӡ");
        set("learn_bonus",                      10);
        set("practice_bonus",           -10);
        set("black_white_ness",         0);
        set("effective_level",          110);
        set("usage/unarmed",            1);
        set("skill_class",                      "lama");
        set("parry_msg",                        ({
                        "$n˫��΢�ϣ�ʹ��һ�С�ǧ��ӭɲ�𡹣���ž����һ����$N��$w����˫��֮�䡣\n",
                        "$n��һת��һ�С�������쳾������$N����$w���֡�\n",
                        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n����������һ�С��ҷ�ȱ���������ĳ����ƣ��Ƶ�$N�����Ա���\n",
                        "$nʩչ��������Թ�ա������赭д�Ļ�����$N�Ĺ��ơ�\n",
                        })
        ); 
        action = ({
                        ([      "action":               
                        "$Nʹ��һ�С��ຣ�����ġ���������ϣ����ƴ�������$n��$l",
                                "dodge":                100,
                                "parry":                100,
                                "force":                100,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ��һ�С����������š������ƻ���Ϊʵ����$n��$l",
                                "dodge":                100,
                                "parry":                100,
                                "force":                 70,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                   "$Nʹ�����ڴ���ӡ�еġ�����ȴ��·����һ������$n��$l",
                                "dodge":                100,
                                "parry":                100,
                                "force":                50,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N˫��һ��ʹ��������Ϊ���𡹣���׼$n��$l�����ĳ�",
                                "dodge":                100,
                                "parry":                100,
                                "force":                150,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N����������ǰ�������Ƴ���һ�С�������ǿա�����$n$l",
                                "dodge":                100,
                                "parry":                100,
                                "force":                140,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ����������ɱֹɱ����������շ��𣬴ӿ��е�ͷ��$n��$l���ƹ���",
                                "dodge":                200,
                                "parry":                200,
                                "force":                150,
                                "damage_type":  "����"
                        ]),
        });
} 
int practice_skill(object me) {
        if( (int)me->query("force") < 5 ) {
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
}        
