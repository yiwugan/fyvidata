//削香剑诀本失传已久，但铁中棠于朱藻处习得，其变化繁复之多，世间剑法难出其右。ximen@sxfy
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "削香剑诀");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("skill_class", "tieflag");
        set("effective_level", 250);
        set("level",           2);
        set("learn_bonus", 20);
        set("practice_bonus", 10);
        set("black_white_ness", -10);
        
        set("parry_msg", ({
        "$n剑随身转，一招「天衣无缝」，$v撒出一片剑影罩向$n全身。\n",
        "$n一声轻笑，手中$v幻化作满天星点把$N的攻势化为无形。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n剑随身转，一招「天衣无缝」，$v撒出一片剑影罩向$n全身。\n",
        "$n一声轻笑，手中$v幻化作满天星点把$N的攻势化为无形。\n",
        }) );   
        action = ({
        ([      "action":
"$N使出一招「雪落寒梅」，手中的$w挽出数个剑花，向$n的$l刺来",
                "dodge":                70,
                "parry":		50,
                "damage":               70,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N使出一招「寒梅吐艳」，$w化为一道剑光刺$n的周身各大要穴",
                "dodge":                80,
                "parry":		60,
                "damage":               80,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N使出一招「三春飞絮」，$w在空中化成一道光环，刺向$n的$l",
                "dodge":                90,
                "parry":		80,
                "damage":               90,
                "damage_type":  "斩伤"
        ]),
        ([      "action":
"$N轻喝一声，一招「缤纷桃花」，手中$w犹如点点繁星，在$n周围形成了一道剑幕",
                "dodge":                80,
                "parry":		80,
                "damage":		100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N左手剑指如飞，右手中的$w一招「鸳鸯双飞」斜刺$n的$l",
                "dodge":                60,
                "parry":		120,
                "damage":		120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N左掌横摆胸前，右手中$w轻轻挥拂，却是一招「四季如春」",
                "dodge":                90,
                "parry":		80,
                "damage":               110,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N一招「柳絮风飘」，$w轻灵地划出几个圆弧，向$n的$l挥去",
                "dodge":                100,
                "parry":		100,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        });
}
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 10 )
            return notify_fail("你的内力不够，无法学习削香剑法。\n");
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 10 ) {
       return notify_fail("你的内力不够，无法学习削香剑法。\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -10);
    write("你按着所学练了一遍削香剑法。\n");
    return 1;
}