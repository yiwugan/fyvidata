 // yue-spear.c
//TIE@FY3
#include <ansi.h> 
inherit SKILL; 
void setup() {
        set("name",                                     "岳家中平枪法");
        set("effective_level",          200);
        set("learn_bonus",              -300);
        set("practice_bonus",           -15);
        set("black_white_ness",         0);
        set("usage/spear",                      1);
        set("usage/parry",                      1);
        set("skill_class",                      "official");
        set("parry_msg",                        ({
                        "$n豪气干云，吟道：「笑谈渴饮匈奴血」，手中的$v由下而上，荡开了$N的$w。\n",
                        "$n吟道：「凭栏处，潇潇雨歇」，手中的$v舞得密不透风，将$N的$w封于丈外。\n",
                        "$n慷慨的诵道：「莫等闲白了少年头，空悲切」，手中的$v化做漫天残照，荡开了$N的$w。\n",
                        "$n手中的$v一抖，枪身暴长，向$N拿$w的手腕刺去。\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n使出一招「怒发冲冠」，将手中的$v舞得密不透风，封住了$N的攻势。\n",
                        "$n使出一招「壮怀激烈」，整个人消失在一团枪影之中。\n",
                        "$n抽身急转，$v直刺$N的双手。\n",
                        "$n将手中的$v一抖，舞出无数枪影，迫得$N连连后退。\n",
                        })
        );
        
        action = ({
                        ([      "action":               
                                        "$N口中吟道: 「待从头收拾旧山河，朝天阙。」，手中$w倒转，枪杆\n由下至上，直向$n的$l打去",
                                "dodge":                32,
                                "parry":                20,
                                "force" :               40,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N长叹道：「靖康耻，犹未雪，臣子恨，何时灭！」，手中$w晃出无数\n枪影，忽然一枪向$n的$l刺去",
                                "dodge":                10,
                                "parry":                40,
                                "force":               15,
                           "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N面带忧色，吟道：「三十功名尘与土。」枪身突转，向$n的下盘扫去",
                                "dodge":                20,
                                "parry":                30,
                                "force":               50,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N一声清啸，「驾长车，踏破贺兰山缺。」，大踏步向前走来，手中$w\n平平递出，直取$n的$l",
                                "force":                30,
                                "dodge":                20,
                                "parry":                30,
                                "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N低头吟哦：「八千里路云和月」，手中$w凌空虚点，蓦地进步跟身，\n向$n扫出一排枪影",
                                "dodge":                20,
                                "parry":                20,
                                "force":               30,
                                "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N慷慨激昂的诵道：「壮志饥餐胡虏肉」，手中长枪忽左忽右，游移不定，募然反\n身向$n的$l挑去",
                                "dodge":                56,
                                "parry":                13,
                                "force":               10,
                                "damage_type":  "刺伤"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 30) {
                return notify_fail("你的内力不够，没有办法练岳家中平枪法。\n");
        }
        
   return 1;
} 
int practice_skill(object me) {
        
        if (me->query_skill("yue-spear",1) > 120)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");
        if((int)me->query("force") <10 ) {
                return notify_fail("你的内力不够，没有办法练习岳家中平枪法。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        write("你按著所学练了一遍岳家中平枪法。\n");
        return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob,weapon;
    int cele;
    
    if( random(damage_bonus) < 100 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "spear"||ob->query("skill_type") == "fork"||ob->query("skill_type") == "staff")
    if(victim->query_skill_mapped("fork") == "jingang-tieguai" 
     ||victim->query_skill_mapped("staff") == "jingang-tieguai"  
     ||victim->query_skill_mapped("spear") == "jingang-tieguai" 
     )
     
    if(me->query_skill("spear")+50 > victim->query_skill("jingang-tieguai")) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n因兵器相克，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("spear")) * 4;
    }
    return 0;
}  