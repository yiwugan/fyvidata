 //duanhun-biao.c
inherit SKILL;
#include <ansi.h>
void setup() {
       set("name", "飞虎追魂镖");
        set("usage/throwing", 1);
        set("skill_class", "new");
        set("effective_level", 140);
        set("learn_bonus", -100);
        set("practice_bonus", -50);
        set("black_white_ness", 10);
        action = ({
        ([      "action":               
"$N肩不抬手不动，突然$w如一条毒龙噬向向$n的$l",
                "dodge":                30,
                "damage":               80,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N双手连环探出，$w随着尖锐的破空声直射$n的$l",
                "dodge":                -50,
                "damage":               100,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N右手一甩，$w从一个意想不到的角度折射$n的$l",
                "dodge":                10,
                "damage":               50,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N真气灌注，手中$w四面散出，继而回飞$n",
                "dodge":                -20,
                "post_action":  "throw_weapon",
                "damage":               200,
                "damage_type":  "刺伤"
        ]),
        });
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 300 ) {
                return notify_fail("你的内力不够，没有办法习得飞虎断魂镖。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 500 ) {
        return notify_fail("你的内力不够，没有办法练习飞虎断魂镖。\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -10);
    write("你将飞虎断魂镖演练了一遍。\n");
    return 1;
}    
