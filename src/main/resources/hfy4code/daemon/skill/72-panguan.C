 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h> 
void setup(){
    set("name", "��ʮ��·�йٱ�");
        set("usage/dagger", 1);
        set("usage/parry",  1);
        set("effective_level", 100);
        set("learn_bonus", -100);
        set("practice_bonus", -5);
        set("practice_limit",50);
        set("black_white_ness", 20);
        set("skill_class","new");
        set("parry_msg", ({
                "$n��$v���һ��裬��ǰ�γ�һƬ���ǵ�㣬�赲��$N�Ľ�����\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n���ֽ�$vֱ��$N�Ļ��ڣ��Ƶ�$N�������ߡ�\n",
        }) );   
        
        
        action = ({
        ([  "action":       "$N����һ��$w����������ʣ������ձʡ�һ����ݵġ������֣�����׷��$n",
                        "dodge":                100,
                        "damage":               200,
                        "damage_type":  "����"
                ]),
        ([  "action":       "$N�ʷ�ͻת������һ�����������ġ��ҡ��֣�����$n��ǰ��Ѩ",
                        "dodge":                150,
                        "damage":               180,
                        "damage_type":  "����"
                ]),
        ([  "action":       "$N���е�$wͻȻ����ʹ�������֮���ϳ���һ�䡺˭���������������磬��$n����������",
                        "dodge":                200,
                        "damage":               520,
                        "damage_type":  "����"
           ]),
        ([  "action":       "$N�ʷ���һת������ͻ��ͻ����������ī����������һ�С�ɽˮ֮�䡻",
                        "dodge":                220,
                        "damage":               300,
                        "damage_type":  "����"
                ]),
        ([  "action":       "$N��ʽ���ϣ��������ֽ���$w�����ֽ�������һ�С�͸ֽ��������$n$l����",
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
        if(damage_bonus < 500 ) return 0;
        if(victim->query_skill_mapped("iron-cloth") == "xuanxinjue"
           ||victim->query_skill_mapped("iron-cloth") == "xisui"
                ||victim->query_skill_mapped("iron-cloth") == "spring-water"
                ) {
                badint = victim->query_skill("iron-cloth")*2+random(victim->query_skill("iron-cloth"));
                if(badint) {
                        victim->receive_wound("kee",badint,me);
                        switch(random(2)) {
                                case 0: return HIY"$N����"+my_weapon->query("name")+HIY"�����ƿգ�һ�̴���$n�Ļ����񹦣�\n"NOR;
                                case 1: return HIY"ֻ����Ӱ����,$N��"+my_weapon->query("name")+HIY"ͻȻ����$n"+HIY"�Ŀ�ҪѨ������\n"NOR;
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