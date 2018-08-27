 // wolf-blade.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "天狼嗜血刀");
        set("usage/blade", 1);
        set("usage/parry", 1); 
        set("effective_level", 220);
        set("learn_bonus", -200);
        set("black_white_ness", -100);
        set("skill_class", "wolf");
         
        set("parry_msg", ({
        "$n一声冷笑，身形不停闪动，手中的$v不偏不倚正砍在$N的$w上面，震得$N手臂发麻！\n",
        "$n大喝一声，高举的$v突然凌空劈下，$N只见一道刀光冲自己迎面而来，连忙收招。\n",
        "$N眼看自己的$w即将击中$n，但却发现对方的$v不知道什么时候已经到了自己的咽喉，连忙回招自保。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n一声冷笑，身形不停闪动，手中的$v不偏不倚正砍在$N的$w上面，震得$N手臂发麻！\n",
        "$n大喝一声，高举的$v突然凌空劈下，$N只见一道刀光冲自己迎面而来，连忙收招。\n",
        "$N眼看自己的$w即将击中$n，但却发现对方的$v不知道什么时候已经到了自己的咽喉，连忙回招自保。\n",
        }) );
        action = ({
        ([      "action":               "$N身形快如奔跑中的野狼，手中的$w带着一阵杀气，劈向$n的$l。",
                "damage":               80,
                "dodge":                100,
                "parry":                100,
                "damage_type":  "劈伤"
        ]),
        ([      "action":               "$N长啸一声，手中的$w带着一股血腥味直扑$n的$l。",
                "dodge":                100,
                "parry":                80,
                "damage":               100,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               "$N犹如觅食的野狼，出手准确！迅疾！凶狠，$n只觉得自己周身都在$N的刀光包围中。",
                "damage":               150,
                "dodge":                100,
                "parry":                120,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               "$N飞跃而起，双手握住$w，用力劈向$n的$l。",
        				"damage":               150,
                "dodge":                140,
                "parry":                120,
                "damage_type":  "劈伤"
        ]),
        ([      "action":               "$N抢攻而上，手中的$w闪出的刀光宛如群狼一般，仿佛要把$n撕成碎片!",
                "damage":               180,
                "dodge":                150,
                "parry":                150,
                "damage_type":  "砍伤"
        ]), 
        });
}         
int practice_skill(object me)
{
    if((int)me->query("force") < 10 ){
        return notify_fail("你的内力或气不够，没有办法练习天狼嗜血刀。\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -10);
    write("你按着所学练了一遍天狼嗜血刀。\n");
    return 1;
}   