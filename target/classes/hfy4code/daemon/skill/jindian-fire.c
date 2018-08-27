 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "����ݻ�");
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        set("practice_damage", 40);
        set("effective_level", 200);
        set("practice_bonus", -5);
        set("skill_class", "quanli");
        set("parry_msg", ({
                "$n��������ͻȻһ�Ż��潫$N�Ƶ����˼�����\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n����һ��������$N��\n",
        }) );
        action = ({
                ([      "action":               "$N���л��һ������$n��$l",
                        "dodge":                100,
                        "parry" :               100,
                        "force":                200,
                        "damage":               100,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$Nһ��[������]���һ�ٷ����$n��$l",
                        "dodge":                30,
                        "parry" :               100,
                        "damage":               100,
                        "force":                100,
                        "damage_type":  "����"
                ]),
                ([      "action":               "������$N�����е����ƣ����ۺ�ɢ���ƻ���$n��$l",
                        "dodge":                120,
                        "parry" :               80,
                        "force":                50,
                        "damage":               100,
                        "damage_type":  "����"
           ]),
                ([      "action":               "$N���Ż�⣬�ݻ�ɢ��$n��$l",
                        "dodge":                100,
                        "parry" :               400,
                        "force":                50,
                        "damage":               100,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����ȫ��Ĺ�����˫�ִ�����ŷ���$n",
                        "dodge":                300,
                        "parry" :               300,
                        "force":                100,
                        "damage":               100,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
    if( (int)me->query_skill("force", 1) < 150 ) {
        return notify_fail("����ڹ��ķ�����㣬�޷�������ݻ𷨡�\n");
        }
        return 1;
}   
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int my_exp, your_exp, damage, lvl;
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        lvl= me->query_skill("jindian-fire",1);
        damage = lvl*2;
        
        if( 10*random(my_exp)>your_exp) {
                victim->receive_wound("kee",damage+random(damage));
                victim->set_temp("last_damage_from",me);
                return HIR "$n���һ����յý�ͷ�ö\n" NOR;
        }       
}   
