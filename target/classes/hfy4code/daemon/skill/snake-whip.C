 // TIE@FY3
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "蛇王鞭法");
        set("usage/whip", 1);
        set("usage/parry", 1);
        set("effective_level", 220);
        set("learn_bonus", -40);
        set("practice_bonus", -20);
        set("black_white_ness", 40);
        set("skill_class", "new");
        set("parry_msg", ({
        "$n使出一招“如蛇之气”，看准$N的来势，手中$v吞吐抑扬，沉静柔实，节节灵通，荡开了$w。\n",
                "$n一招“毒蛇扫林”，手中$v急力向右侧上猛转，迎向$N的$w，鞭身莫名抖动，连环震得$N双臂酸麻。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n手中$v抡动，腰身成弓形，一招“群蛇出穴”，随着$N的攻势飘动。\n",
        "$n身形怪异起伏，$v横空一扫，一招“双蛇探路”，似在身前，鞭却到了$N的身后。\n",
        }) );
        action = ({
                ([
                        "action":               
                        "$N手中$w抡动，鞭风汹涌，回旋出击，一招“盘蛇击虎”直打$n的$l！",
                        "dodge":                500,
                        "parry" :               500,
                        "force" :               500,
                        "damage_type":  "瘀伤"
                ]),
        ([
            "action":               
            "$N阴森森地冷哼一声，手中$w舞直，一招“白蛇通天”，刺向$n的$l！",
            "dodge":                300,
            "parry" :               300,
            "force" :               300,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":               
            "$N手中$w连摆，身随鞭舞，一招“青蛇吐信”，竟在力尽之处再度发力，直打$n的$l！",
            "dodge":                500,
            "parry" :               500,
            "force" :               400,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":              
            "$N手中$w左右摇摆不定，一招“金蛇寻穴”，鞭鞭皆打向$n的$l！",
            "dodge":                700,
            "parry" :               700,
            "force" :               700,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":               
            "$N手中$w当头一鞭，紧跟着鞭梢一摆，一招“银蛇缠枝”，顺着$n身形中的破绽，直击弱处！",
            "dodge":                500,
            "parry" :               500,
            "force" :               600,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":               
            "$N手中$w圈圈点点，步法连绵，一招“草影惊蛇”，虚虚实实向$n的$l打去！",
            "dodge":                700,
            "parry" :               700,
            "force" :               300,
            "damage_type":  "瘀伤"
        ]),
        ([
            "action":               
            "$N使出一招“巨蛇摆尾”，鞭头直直砸向$n的$l！",
            "dodge":                700,
            "parry" :               700,
            "force" :               100,
            "damage_type":  "瘀伤"
    ]),
        ([
            "action":               
            "$N手中$w迎头抽去，鞭梢摆动，一招“灵蛇戏珠”，竟从$n的的身后打来！",
            "dodge":                300,
            "parry" :               300,
            "force" :               700,
            "damage_type":  "瘀伤"
        ]), 
        });
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ){
                return notify_fail("你的内力不够，没有办法练蛇王鞭法，多练些内力再来吧。\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 10 ){
                return notify_fail("你的内力或气不够，没有办法练习蛇王鞭法。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        write("你按著所学练了一遍蛇王鞭法。\n");
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