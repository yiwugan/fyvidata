 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h> 
void setup(){
    set("name", "七十二路判官笔");
        set("usage/dagger", 1);
        set("usage/parry",  1);
        set("effective_level", 100);
        set("learn_bonus", -100);
        set("practice_bonus", -5);
        set("practice_limit",50);
        set("black_white_ness", 20);
        set("skill_class","new");
        set("parry_msg", ({
                "$n将$v左右挥舞，身前形成一片繁星点点，阻挡了$N的进攻。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n反手将$v直刺$N的虎口，逼得$N退让三尺。\n",
        }) );   
        
        
        action = ({
        ([  "action":       "$N右手一挥$w，从左上起笔，右下收笔。一个狂草的「死」字，连连追击$n",
                        "dodge":                100,
                        "damage":               200,
                        "damage_type":  "刺伤"
                ]),
        ([  "action":       "$N笔锋突转，竟是一个铁画银钩的『我』字，连击$n身前各穴",
                        "dodge":                150,
                        "damage":               180,
                        "damage_type":  "刺伤"
                ]),
        ([  "action":       "$N手中的$w突然连绵使出，恍惚之间认出是一句『谁入地狱』，气势如虹，让$n喘不过气来",
                        "dodge":                200,
                        "damage":               520,
                        "damage_type":  "刺伤"
           ]),
        ([  "action":       "$N笔锋再一转，笔势突快突慢，犹如泼墨而画，正是一招『山水之间』",
                        "dodge":                220,
                        "damage":               300,
                        "damage_type":  "刺伤"
                ]),
        ([  "action":       "$N招式用老，换过左手紧握$w，右手紧握左腕，一招『透纸而出』向$n$l反噬",
                        "dodge":                300,
                        "damage":               100,
                        "damage_type":  "刺伤"
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
                                case 0: return HIY"$N手中"+my_weapon->query("name")+HIY"气劲破空，一刺穿了$n的护体神功！\n"NOR;
                                case 1: return HIY"只觉黑影重重,$N的"+my_weapon->query("name")+HIY"突然刺中$n"+HIY"心口要穴．．．\n"NOR;
                        }
                }
        }
        return 0;
} 
int practice_skill(object me)
{
        if( (int)me->query("force") < 50 ){
            return notify_fail("你的内力不够。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
   return 1;
}    
