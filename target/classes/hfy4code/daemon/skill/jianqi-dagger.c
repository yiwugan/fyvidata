 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h> 
void setup(){
    set("name", "�����");
        set("usage/dagger", 1);
        set("usage/parry",  1);
        set("effective_level", 200);
        set("learn_bonus", -100);
        set("practice_bonus", -5);
        set("practice_limit",50);
        set("black_white_ness", 20);
        set("skill_class","new");
        set("parry_msg", ({
                "$n�ɿ�ؽ�$v�趯��������ߵ�һ�����������赲��$N�Ľ�����\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n���е�$v��������������������ǧǧ����ĳ������$N��\n",
        }) );   
        
        
        action = ({
        ([  "action":       "$N����һ��$w��һ�轣�����ķ���$n��ɽɫ��ɥ�����������Ϊ֮�õͰ�",
                        "dodge":                100,
                        "damage":               200,
                        "damage_type":  "����"
                ]),
        ([  "action":       "$N����ͻת��һ�С���������䡻����Ⱥ��������",
                        "dodge":                150,
                        "damage":               180,
                        "damage_type":  "����"
                ]),
        ([  "action":       "$N���е�$wͻȻʹ����筴���������į��������������������ŭ�����罭������⣬��
$n����������",
                        "dodge":                200,
                        "damage":               220,
                        "damage_type":  "����"
           ]),
        ([  "action":       "$N����һת�������ڶ���ľ�ѹ�������ʯ�ǲ���ɪ��ʹ����ֻ�������Ҽ��������գ���
�������¶�������̬�����Ѽ�",
                        "dodge":                220,
                        "damage":               300,
                        "damage_type":  "����"
                ]),
        ([  "action":       "$N˫�ֽ���$w��һ�С��糾��ͥ�����ң�����ɽת���$n$l����",
                        "dodge":                300,
                        "damage":               100,
                        "damage_type":  "����"
                ]),
        });
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object my_weapon;
        int badint;
        my_weapon=me->query_temp("weapon");
        if(damage_bonus < 300 ) return 0;
        if(victim->query_skill_mapped("iron-cloth") == "xuanxinjue"
           ||victim->query_skill_mapped("iron-cloth") == "xisui"
                ||victim->query_skill_mapped("iron-cloth") == "spring-water"
                ) {
                badint = victim->query_skill("iron-cloth")*2+random(victim->query_skill("iron-cloth"));
                if(badint) {
                        victim->receive_wound("kee",badint,me);
                        switch(random(2)) {
                                case 0: return HIW"$N����"+my_weapon->query("name")+"������ʢ��һ������$n�Ļ����񹦣�\n"NOR;
                                case 1: return HIW"$nֻ����Χһ��,$N��"+my_weapon->query("name")+"���ѵ���ǰ������\n"NOR;
                        }
                }
        }
        return 0;
} 
int practice_skill(object me)
{
        if( (int)me->query("force") < 50 ){
            return notify_fail("�������������\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
   return 1;
}    
