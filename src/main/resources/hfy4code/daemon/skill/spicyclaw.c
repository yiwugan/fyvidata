 // spicyclaw.c
inherit SKILL;
void setup(){
        set("name", "油流麻香手");
        set("usage/unarmed", 1);
        set("practice_damage", 25);
        
        set("parry_msg", ({
        "$n急划$N的脉门，逼得$N中途撤回手中的$w。\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n急划$N的脉门，逼得$N中途撤招。\n",
        }) ); 
        action = ({
                ([      "action":               "$N左掌微分，右手一长使出一招「毒龙扑舟」，抓向$n的$l",
                        "dodge":                -30,
                        "parry":                -70,
                        "force":                160,
                        "damage_type":  "抓伤"
                ]),
                ([      "action":               "$N倏地一个转身，双手一翻「撺锅手」直掼$n$l",
                        "dodge":                -10,
                        "parry":                -60,
                        "force":                140,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N身子微斜，随即跨出一步，左手忽掌忽爪使出「撮灰手」，拍向$n的$l",
                        "dodge":                -30,
                        "parry":                -40,
                        "force":                120,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N使出「青蛇十段锦」，双手滑溜异常对准$n的$l抓去",
                        "dodge":                10,
                        "parry":                -60,
                        "force":                140,
                        "damage_type":  "抓伤"
                ]),
                ([      "action":               "$N左手虚晃，右掌飘飘，一招「梁上君子」击向$n$l",
                        "dodge":                -20,
                   "parry":                -50,
                        "force":                150,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N使出「拨草寻履」，凌空跃起，冷不防在落地前对准$n$l踢出一脚",
                        "dodge":                -70,
                        "parry":                -40,
                        "force":                180,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N右手在$n$l划过，随後一招「随棍上身」左爪又向同一方位抓到",
                        "parry":                -90,
                        "force":                100,
                        "damage_type":  "抓伤"
                ]),
        });
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 80 ){
                return notify_fail("你的内力太弱，无法练油流麻香手。\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 3 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -3);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0; 
   if( random(damage_bonus/5) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 2 );
                switch(random(3)) {
                        case 0: return "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n";
                        case 1: return "$N劲力一吐，$n的$l发出「喀」地一声爆响！\n";
                        case 2: return "只听见$n的$l「喀」地一声 ...\n";
                }
        }
}        
