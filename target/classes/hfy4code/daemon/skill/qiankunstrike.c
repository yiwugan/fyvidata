 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "乾坤大挪移掌");
        set("usage/unarmed", 1);
        set("skill_class", "taoist");
        set("parry_msg", ({
        "$n身法轻灵，使出一招「芳草映斜阳」，「叮」的一声将$N的$w弹开。\n",
        "$n略一转身，掌式飘乎不定，一招「明月几时有」拍向$N拿着$w的手。\n",
        "$n左掌作日字式，右掌走月字决，日月相辉映，一招「日月正同辉」，引偏了$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n身形不动，内力由内到外，澎湃而出，一招「铁肩挑日月」，逼得$N撤招自保。\n",
        "$n身形圆转，以内力鼓动袍袖，一招「袖里有乾坤」，轻描淡写的化解了$N的攻势。\n",
        }) );
        
        action = ({
        ([      "action":               
"$N平平淡淡的使出一招「黄沙路漫漫」，左掌暗藏诸多变化，右掌穿出击向$n的$l",
                "dodge":                -100,
                "parry":                100,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N急出一招「平地起风云」，左掌化虚为实击向$n的$l",
                "dodge":                -100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N以内力发出长啸，声彻九天，一招「长歌啸九天」，一掌拍向$n的$l",
                "dodge":                -100,
                "parry":                100,
                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N内力滔滔，掌势浑厚，一招「大江东流去」浩浩荡荡，对准$n的$l连续拍出",
                "dodge":                -100,
                "parry":                100,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N掌风隐隐带着雷声，右掌推出，一招「狂雷冲霄汉」无坚不催地击向$n$l",
                "dodge":                -100,
                "parry":                100,
                "force":                240,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N掌势绵密，掌风轻柔，一招「细雨伴春风」，从空中当头向$n的$l出掌攻击",
                "dodge":                -200,
                "parry":                200,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        });
}
int practice_skill(object me)
{
    if( (int)me->query("force") < 5 ){
        return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -5);
    return 1;
}    
