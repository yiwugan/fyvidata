 // qiuzhi-sword.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "虬枝剑式");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("practice_limit",120);
        set("skill_class", "mei");
        set("effective_level", 220);
        set("learn_bonus", -500);
        set("practice_bonus", 10);
        set("black_white_ness", 20);
        set("unarmed_parry_msg",({
                "$n手中$v一圈，一招“寒梅吐蕊”刚好封住$N的攻势。\n",
                "$n一招“乍惊梅多”手中的$v攻向$N必救之处。\n", 
                "$n手中的$v一抖，挽出一片剑花，一招“梅林花落”将$N全身围住。\n",
                                        })      
        );
        action = ({
        ([      "action":               
"$N手中$w一圈，然后猛然点向$n的$l，正是“虬枝剑式”中的“寒梅吐蕊”",
                "dodge":                140,
				"parry":                140,
                "damage":               240,
                "force":                240,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N左手一弹，手中$w突地一探，方向却是斜掠而上，活像一枝梅几乍然横出，
攻向$n的$l。正是绝学“冷梅拂面”",
                "dodge":                142,
				"parry":                142,
                "damage":               250,
                "force":                250,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N飞快的比出二式，却是虬枝剑招中的连环杀手，只见$N二臂齐举，一合之下，
双掌向上一翻一压，手中$w拂向$n。正是“乍惊梅多”的招式。",
                "dodge":                130,
				"parry":                130,
                "damage":               230,
                "force":                230,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"缕缕剑气从$N$w透出，剑光一匝宛如长蛇出洞，刺向$n$l，正是“虬枝剑法”的
精妙绝学“梅占先春”",
                "dodge":                137,
				"parry":                137,
                "damage":               340,
                "force":                340,
                "damage_type":  "刺伤"
        ]), 
               
        });
}
int valid_learn(object me)
{
    if((int)me->query("max_force") < 200 ) {
            return notify_fail("你的内力不够，没有办法练虬枝剑式。\n");
        }
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
}   


void skill_improved(object me)
{
    int s;
    s = me->query_skill("qiuzhi-sword", 1);
    if (s== 100) {
       tell_object(me,HIW "你对虬枝剑式有了新的了解！\n"NOR);
       } 
    if (s== 150 && me->query("class")=="mei") {
       tell_object(me,HIW "由于对虬枝剑式的深入了解，你的［寒梅落］达到了新的境界！\n"NOR);
       me->set("once_menpai/mei",1);
       } 
}      
        
mixed hit_ob(object me,object victim)
{
	int dam;
	dam = me->query("max_sen");
	if (me->query_temp("hanmeiluo")) {
                victim->receive_wound("sen", dam/5 +  random(dam/10), me);
				return (HIY"点点光华流散，耀目的剑光已刺入了$n"HIY"要害！\n"NOR);
	}
	else if( random(me->query_skill("qiuzhi-sword", 1)) > 30 ) {
                victim->receive_damage("sen", dam/10 +  random(dam/20), me);
				return (HIY"耀目的剑光刺得$n"HIY"睁不开眼睛！\n"NOR);
	}
	else
       return (""); 
}      
