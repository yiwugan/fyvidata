 // yue-spear.c
//TIE@FY3
inherit SKILL; 
void setup() {
        set("name",                                     "飞云神枪");
        set("effective_level",          350);
        set("learn_bonus",              -1000);
        set("practice_bonus",           -1500);
        set("black_white_ness",         0);
        set("usage/spear",                      1);
        set("usage/parry",                      1);
        set("skill_class",                      "new");
        set("parry_msg",                        ({
                        "$n一式「云深不知处」，手中的$v由下而上，荡开了$N的$w。\n",
                        "好一招「万里无云」，$n举起手中的$v舞得密不透风，将$N的$w封于丈外。\n",
                        "$n后纵半步，一式「波谲云诡」，手中的$v化做漫天残照，荡开了$N的$w。\n",
                        "$n手中的$v一抖，枪身暴长，一式「拨云见日」向$N拿$w的手腕刺去。\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n使出一招「风云变幻」，将手中的$v舞得密不透风，封住了$N的攻势。\n",
                        "$n使出一招「风云际会」，整个人消失在一团枪影之中。\n",
                        "$n抽身急转，一招「裂石穿云」$v直刺$N的双手。\n",
                        "$n将手中的$v一抖，一招「行云流水」舞出无数枪影，迫得$N连连后退。\n",
                        })
        );
        
        action = ({
                        ([      "action":               
                                        "$N一招「高耸入云」，手中$w倒转，枪杆\n由下至上，直向$n的$l打去",
                                "dodge":                32,
                                "parry":                20,
                                "force" :               40,
                                "damage":               99,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N一招「巫山云雨」，手中$w晃出无数\n枪影，忽然一枪向$n的$l刺去",
                                "dodge":                10,
                                "parry":                40,
                                "force":               15,
                                "damage":               199,                                 
                           "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N一招「闲云野鹤」，枪身突转，向$n的下盘扫去",
                                "dodge":                20,
                                "parry":                30,
                                "force":               50,
                                "damage":               299,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N一声清啸，一招「烟消云散」，大踏步向前走来，手中$w\n平平递出，直取$n的$l",
                                "force":                30,
                                "dodge":                20,
                                "parry":                30,
                                "damage":               499,
                                "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N一招「云泥之别」，手中$w凌空虚点，蓦地进步跟身，\n向$n扫出一排枪影",
                                "dodge":                20,
                                "parry":                20,
                                "force":               30,
                                "damage":               999,
                                "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N一招「浮云朝露」，手中长枪忽左忽右，游移不定，募然反\n身向$n的$l挑去",
                                "dodge":                56,
                                "parry":                13,
                                "force":               10,
                                "damage":               9999,
                                "damage_type":  "刺伤"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 30) {
                return notify_fail("你的内力不够，没有办法练飞云神枪枪法。\n");
        }
        
   return 1;
} 
int practice_skill(object me) {
        
        if (me->query_skill("yue-spear",1) > 120)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");
        if((int)me->query("force") <10 ) {
                return notify_fail("你的内力不够，没有办法练习飞云神枪枪法。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        write("你按著所学练了一遍飞云神枪枪法。\n");
        return 1;
}  
