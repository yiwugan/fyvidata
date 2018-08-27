 // tangsi.c
#include <ansi.h> 
inherit SKILL;
void setup() {
        set("name", "七杀剑法");
        set("usage/sword", 1);
        set("usage/whip", 1);
        set("usage/parry", 1);
        set("skill_class", "tang");
        set("effective_level", 150);
        set("learn_bonus", -50);
        set("practice_bonus", 10);
        set("black_white_ness", 15);
        set("parry_msg", ({
        "$n使出一招「君臣庆会」，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n使出「紫府同宫」，将$N的$w封于丈外。\n",
        "$n使出一招「七杀朝斗」，手中的$v化做漫天剑雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「石中隐玉」，向$N拿$w的手腕削去。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n将手中的$v舞得密不透风，一式「日月并明」封住了$N的攻势。\n",
        "$n反手一招「日月反背」，整个人消失在一团剑光之中。\n",
        "$n使出一招「日照雷门」，$v直刺$N的双手。\n",
        "$n将手中的$v化做七条剑气，一式「明珠出海」迫得$N连连后退。\n",
        }) );   
        action = ({
        ([      "action":               
"$N使一招「月朗天门」，手中$w如一条银蛇般刺向$n的$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出七煞剑法中的「木火通明」，剑光霍霍斩向$n的$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「极向离明」，身形陡然滑出数尺，手中$w斩向$n的$l",
                "dodge":                30,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「英星入庙」对准$n的$l刺出一剑",
                "dodge":                40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「紫府朝垣」对准$n的$l斜斜刺出一剑",
                "dodge":                40,
                "force":                120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「机月同梁」刺向$n的$l",
                "dodge":                20,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「月生沧海」反手对准$n$l一剑刺去",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招「马头带剑」画出一道光弧刺向$n的$l",
                "dodge":                30,
                "damage":               50,
                "force":                100,
                "damage_type":  "刺伤"
        ]),
        });
}
