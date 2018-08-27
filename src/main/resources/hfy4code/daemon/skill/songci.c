 // songci.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "宋词掌法");
        set("learn_bonus",              50);
        set("practice_bonus",   10);
        set("effective_level",  70);
        set("usage/unarmed",    1);
        set("skill_class",              "tang");
        
        set("parry_msg",                ({
                                                "$n一招「明月几时有」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
                                                "$n右拳虚幌，左拳一招「大江东去」，逼得$N后退三步。\n",
                                                "$n以守为攻，一招「左牵黄，右擎苍」，猛击$N握$w的手腕。\n",
                                                "$n一招「昨夜雨疏风骤」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
                                                        })
        );
        set("unarmed_parry_msg",({
                                                "$n一招「帘卷西风」，逼得$N中途撤招。\n",
                                                "$n脚走阴阳，一招「气吞万里如虎」，攻$N之必救。\n",
                                                "$n左拳击下，右拳自保，一招「烟柳断肠处」，将$N封于尺外。\n",
                                                "$n双拳齐出，使出一招「晓风残月」，$N的功势入泥牛入海，消失得无影无踪。\n",
                                                        })
        );
                                           
        action = ({
                        ([      "action":               "$N使一招「无意苦争春」，对准$n的$l「呼」地一拳",
                                "dodge":                -40,
                                "parry":                40,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N扬起拳头，一招「只有香如故」便往$n的$l招呼过去",
                                "dodge":                -30,
                                "parry":                30,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N左手虚晃，右拳「起舞弄清影」往$n的$l击出",
                                "dodge":                -30,
                                "parry":                30,
                           "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N步履一沉，左拳拉开，右拳使出「一尊还酹江月」击向$n$l",
                                "dodge":                -30,
                                "parry":                30,
                                "damage_type":  "瘀伤"
                        ]),
        });
} 
