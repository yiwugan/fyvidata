 // six-chaos-sword.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "六阴追魂剑法");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("black_white_ness", 400);
        set("effective_level", 400);
        set("learn_bonus", 400);
        set("practice_bonus", 400);

        set("parry_msg", ({
        "$n不退反进，气走周天，一招「鬼魅无边」，手中的$v狠狠磕开了$N的$w。\n",
                "$n回剑自守，一招「鬼火飘零」，架住了$N的$w。\n",
                "$n一招「群魔乱舞」，手中的$v化作千百把，护住了全身。\n",
                "$n手中的$v自上削下，几乎将$N的$w削成两段。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n使出一招「万炼魔障」，在身前布起了一道铜墙铁壁，封住了$N的攻势。\n",
                "$n一抖手中的$v，使出一招「碧灵魔遁」，手中的$v护住了全身。\n",
                "$n将$v往地上一刺，$v反弹起来，刚好直刺$N的双臂。\n",
                "$n举剑静立，一股内力从剑梢透出，逼开了$N。\n",
        }) ); 
        action = ({
                ([      "name":                 "群魔乱舞",
                        "action":               "$N使一招「群魔乱舞」，手中$w狂风骤雨般地向$n的$l连攻数剑",
                        "dodge":                50,
                        "damage":               170,
                        "damage_type":  "刺伤"
                ]),
                ([      "name":                 "厉鬼缠身",
                        "action":               "$N身形一转，一招「厉鬼缠身」$w斩向$n的$l",
                        "dodge":                -50,
                        "damage":               20,
                        "damage_type":  "刺伤"
                ]),
                ([      "name":                 "百鬼夜行",
                        "action":               "$N舞动$w，一招「百鬼夜行」挟著闪闪剑光刺向$n的$l",
                        "dodge":                -40,
                        "damage_type":  "刺伤"
                ]),
                ([      "name":                 "饿鬼拦路",
                        "action":               "$N手中$w一抖，使出「饿鬼拦路」往$n的$l刺出一剑",
                   "dodge":                -40,
                        "damage":               40,
                        "damage_type":  "刺伤"
                ]),
                ([      "name":                 "鬼影幢幢",
                        "action":               "$N手中$w剑光暴长，一招「鬼影幢幢」往$n$l刺去",
                        "dodge":                -60,
                        "damage":               20,
                        "damage_type":  "刺伤"
                ]),
                ([      "name":                 "秋坟鬼唱",
                        "action":               "$N手中$w直指$n$l，一招「秋坟鬼唱」发出逼人剑气刺去",
                        "dodge":                -20,
                        "damage":               50,
                        "damage_type":  "刺伤"
                ]),
        });
}
int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_force") < 100 ){
                return notify_fail("你的内力不够，没有办法练六阴追魂剑。\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
}
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ){
                return notify_fail("你的内力或气不够，没有办法练习六阴追魂剑。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        write("你按著所学练了一遍六阴追魂剑法。\n");
        return 1;
} 
void skill_improved(object me)
{
        if( (int)me->query_skill("six-chaos-sword", 1)  % 10 == 0 ) {
                tell_object(me,RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 1000);
        } else
                me->add("bellicosity", 100);
} 
