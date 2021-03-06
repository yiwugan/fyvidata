 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "天狼百破拳");
        set("usage/unarmed", 1);
        set("effective_level", 120);
        set("learn_bonus", 10);
        set("black_white_ness", -10);
        set("skill_class", "wolf");
        set("parry_msg", ({
        "$n神色冷厉紧紧盯着$N，令$N感到无法进招。 \n",
                "$n左手一格，右手飞抓$N破绽，$N连忙退步自保。 \n",
                "$n双拳交叉挥出，劲风刚烈，迫得$N连连后退。 \n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n神色冷厉紧紧盯着$N，令$N感到无法进招。 \n",
        "$n左手一格，右手飞抓$N破绽，$N连忙退步自保。 \n",
        "$n双拳交叉挥出，劲风刚烈，迫得$N连连后退。 \n",
        }) );
        
        action = ({
        ([      "action":               
"$N绕着$n来回游走，突然觑个空隙闪电般猛击$n的$l。 ",
                "dodge":                110,
                "parry":                110,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N横臂扫来，半途身子一弓，双手合拢抓向$n的$l。 ",
                "dodge":                130,
                "parry":                130,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N厉声长啸，忽然一跃而起，合肘攻向$n的$l。 ",
                "dodge":                150,
                "parry":                150,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N斜身一转，右掌成爪虚晃$n面门，左掌蓄力斜劈$n的$l。 ",
                "dodge":                170,
                "parry":                170,
                "damage":                70,
                "damage_type":  "瘀伤"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
        if((int)me->query_skill("wolf-force", 1) < 10){
            return notify_fail("你的天狼心法火候不足，无法练天狼百破拳。\n");
        }
        if (me->query("combat_exp")<2000000 && me->query_skill("wolf-strike",1)>150){
                tell_object(me,"你的实战经验太差,无法进一步领略天狼百破拳。\n");
                return 0;
        }
        if (me->query("combat_exp")<3000000 && me->query_skill("wolf-strike",1)>160){
                tell_object(me,"你的实战经验太差,无法进一步领略天狼百破拳。\n");
                return 0;
        }
        if (me->query("combat_exp")<4500000 && me->query_skill("wolf-strike",1)>170){
                tell_object(me,"你的实战经验太差,无法进一步领略天狼百破拳。\n");
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        
        if( (int)me->query("force") < 5 ){
            return notify_fail("你的内力不够了，休息一下再练吧。\n");
   }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        return 1;
}    
