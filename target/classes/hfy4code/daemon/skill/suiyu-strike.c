 //ximen@glqx.net
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "碎玉拳法");
        set("usage/unarmed", 1);
        set("skill_class", "tieflag");
        set("effective_level", 230);
        set("learn_bonus", -10);
        set("level",         3);
        set("practice_bonus", 10);
        set("black_white_ness", 20);
        
        set("parry_msg", ({
        "$n双拳一错，把$N攻势消于无形。\n",
        "$n不守反攻，一拳直击要害，$N被迫撤回攻势。\n",
        "$n一拳紧接一拳，拳风竟活生生地把$N的攻势逼出圈外。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n拳法展开，把自身守得滴水不漏。\n",
        "$n往空处击出数拳，竟把$N的进攻路线全部全部封住。\n",
        }) );   
        action = ({ 
                ([      "action":               "$N踏步上前，拳头「呼」的一声直击$n的要害", 
                        "dodge":                 50, 
                        "parry":                250, 
                        "force" :               100, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N吐气开声，拳头连环击出，如暴风骤雨般直往$n攻去", 
                        "dodge":                250, 
                        "force" :               150, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N侧身避开$n的攻势，左拳从下击出，右拳直击$n面门", 
                        "dodge":                150, 
                        "parry":                100, 
                        "force" :               250, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$n只觉得拳风迎面扑来，发现$N的拳头竟在眼前由小变大", 
                        "dodge":                100, 
                        "force" :               300, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N转身反打，右拳全力击向$n的太阳穴", 
                        "dodge":                150, 
                        "parry":                100, 
                        "force" :               250, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N身形飘忽，欺近$n身旁突然双拳全力击出", 
                        "dodge":                150, 
                        "parry":                100, 
                        "force":                250, 
                        "damage_type":  "瘀伤" 
                ]), 
        }); 
}
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 500 )
            return notify_fail("你的内力不够，没有办法练碎玉拳法。\n");
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 5 ) {
       return notify_fail("你的内力不够，没有办法练习碎玉拳法。\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -5);
    write("你按着所学练了一遍碎玉拳法。\n");
    return 1;
} 
