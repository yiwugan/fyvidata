 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// huanhua-sword.c 
inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name", "��ˮ����");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("effective_level", 250);
        set("practice_bonus", -5);
        set("skill_class", "shenzhou");
        set("parry_msg", ({
                "$nһ��"HIB"[����һ��]"NOR"�����ؽ����е�$v��������ǰ��ǿ�ҵĽ��罫$N�Ƶ����˼�����\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n���е�$v�����ػӳ������Ҳ����Ľ������$N��\n",
        }) );
        
        action = ({
                ([      "action":               "$N���е�$wʹ��"HIR"[�������]"NOR"����������ѽ���������������ڰ�ص���$n��$l",
                        "dodge":                200,
                        "parry" :               200,
                        "force":                400,
                        "damage":               200,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N���е�$w���裬"HIY"[������ɳ]"NOR"�󱩷��еĹ�ɳ������$n��$l",
                        "dodge":                100,
                        "parry" :               200,
                        "damage":               200,
                        "force":                300,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N���е�$w�������ƣ����ۺ�ɢ�ؿ���$n��$l",
                        "dodge":                30,
                        "parry" :               100,
                        "force":                100,
                        "damage":               200,
                        "damage_type":  "����"
           ]),
                ([      "action":               "$N�ζ����е�$w������������֣�������е���Ҷ��һ��["YEL"��"RED"Ů"BLU"ɢ"CYN"��]"NOR"ɢ��$n��$l",
                        "dodge":                200,
                        "parry" :               110,
                        "force":                100,
                        "damage":               200,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����ȫ��Ĺ��������е�$w��̹Ǻ�������$n",
                        "dodge":                100,
                        "parry" :               400,
                        "force":                200,
                        "damage":               200,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 20 ) {
                return notify_fail("����ڹ��ķ�����㣬�޷�����ˮ������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        object weapon; 
        if(!::practice_skill(me)) {
                return 0;
        }
        if( (int)me->query("kee") < 40 )
                return notify_fail("����������������Ž�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 40);
        return 1;
}       
