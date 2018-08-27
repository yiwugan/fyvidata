 // TIE@FY3
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "梵音天龙鞭法");
        set("usage/whip", 1);
        set("usage/parry", 1);
        set("effective_level", 180);
        set("learn_bonus", -40);
        set("practice_bonus", -20);
        set("black_white_ness", 40);
        set("skill_class", "shaolin");
        set("parry_msg", ({
        "$n使出一招“双眼若明行自稳”，拿桩站稳，不躲不闪，看准$N的来势，手中$v一扬，荡开了$w。\n",
                "$n一招“三心发动信自深”，凝神运力，手中$v迎向$N的$w，震得$N双臂酸麻，$w险些脱手。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n手中$v抡动，身形借力，一招“脚底无根似飘萍”，随着$N的攻势飘动。\n",
        "$n身形乱动，$v怪抡，一招“才出歧途又迷踪”，人却转到$N的身。\n",
        }) );
        action = ({
                ([
                        "action":               
                        "$N手中$w抡动，鞭风汹涌，去式似游龙，一招“风云湖海昔犹龙”直打$n的$l！",
                        "dodge":                500,
                        "parry" :               500,
                        "force" :               500,
                        "damage_type":  "瘀伤"
                ]),
        ([
            "action":               
            "$N眼角流出一丝笑意,手中$w圈动，一招“经卷蒲团笑人生”，缠向$n的$l！",
            "dodge":                300,
            "parry" :               300,
            "force" :               300,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":               
            "$N手中$w连摆，身形急进，一招“傀儡登场皆作戏”，竟幻出两个人影，直打$n的$l！",
            "dodge":                500,
            "parry" :               500,
            "force" :               400,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":              
            "$N手中$w带动身形旋转，一招“个中谁是主人公”，鞭鞭皆打向$n的$l！",
            "dodge":                700,
            "parry" :               700,
            "force" :               700,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":               
            "$N手中$w当头一鞭，紧跟着鞭梢一摆，一招“一方正后方方正”，竟幻出层层鞭影，将$n围在其中！",
            "dodge":                500,
            "parry" :               500,
            "force" :               600,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":               
            "$N手中$w圈圈点点，步法连绵，一招“初步迷时步步迷”，虚虚实实向$n的$l打去！",
            "dodge":                700,
            "parry" :               700,
            "force" :               300,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":               
            "$N使出一招“净不须禅禅须净”，鞭头直直砸向$n的$l！",
            "dodge":                700,
            "parry" :               700,
            "force" :               100,
            "damage_type":  "瘀伤"
    ]),
        ([
            "action":               
            "$N手中$w迎头抽去，鞭梢摆动，一招“未能知有岂知空”，竟从$n的的身后打来！",
            "dodge":                300,
            "parry" :               300,
            "force" :               700,
            "damage_type":  "瘀伤"
        ]), 
        });
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 150 ){
                return notify_fail("你的内力不够，没有办法练梵音天龙鞭法，多练些内力再来吧。\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 10 ){
                return notify_fail("你的内力或气不够，没有办法练习梵音天龙鞭法。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        write("你按著所学练了一遍梵音天龙鞭法。\n");
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
     
    if(me->query_skill("whip")+50 > victim->query_skill("jingang-tieguai")) {
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
    return random(me->query_skill("whip")) * 4;
    }
    return 0;
}        