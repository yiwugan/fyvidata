 // fumostaff.c
inherit SKILL;
void setup() {
        set("name", "韦陀伏魔杖法");
        set("usage/staff", 1);
        set("usage/parry", 1);
        set("learn_bonus", 10);
        set("practice_bonus", -5);
        set("black_white_ness", 0);
        set("skill_class", "shaolin");
        set("parry_msg", ({
        "结果$n用手中的$v格开了$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        }) );
        action = ({
        ([      "action":               
"$N使一招「空王不语」，手中$w舞动如飞，扫向$n下盘！",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N挥起$w，一招「满目苍生」，手中$w只攻不守，攻向$n$l！",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N横过手中$w，使出「杖掠横空」，手中$w劈空而下，击向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「苦海慈航」，$w大开大合，撞向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        });
} 
int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 35 ) {
                return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 10) {
                return notify_fail("你的内力不够练习。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
}   
