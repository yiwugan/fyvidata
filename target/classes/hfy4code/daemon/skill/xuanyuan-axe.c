 inherit SKILL;
#include <ansi.h> 
void setup(){
        set("name", "轩辕斧法");
        set("usage/axe", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 200);
        set("learn_bonus", 0);
        set("practice_bonus", -5);
        set("practice_limit",120);
        set("black_white_ness", 0);
        set("skill_class", "knight");
        
        set("parry_msg", ({
        "结果$n一招「神行飘缈」，挥动手中$v格开了$N的$w。\n",
        "结果$n手中$v一分，一招「神转天盘」，斜劈$N的$w。\n",
        "结果$n手中$v抡动如飞，一招「二神垂眉」，荡开$N的$w。\n",
        "结果$n手中$v飞速旋转，一招「鬼斧神工」，反扫$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n手中的$v舞动如飞，一招「鬼决天河」，封住了$N的攻势。\n",
        "$n身影晃动，一招「鬼哭神嚎」，反砍$N的下盘。\n",
        "$n身形一矮，一招「万魔同体」，躲过$N的攻势。\n",
        "$n手中的$v自上而下，一招「幽冥幻影」，反劈$N的要害。\n",
        }) );   
        action = ({
        ([      "action":               
"$N手中$w舞动，脚步一沉，一招「阴阳三合」，手中$w如流星般直劈$n的$l！",
                "damage":               210,
                "dodge":                210,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「圜则九重」如惊鸿一撇般令$n毫无警讯，一瞬间$w已来至$n的面前！",
                "damage":               210,
                "dodge":                210,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w如陀螺般旋转不停，一招「天何所沓」，直取$n的各处要害！",
                "damage":               200,
                "dodge":                140,
                "parry":                100,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w牵动著周遭的气流，一招「日月安属」，漩涡般向$n$l劈去！",
                "damage":               150,
                "dodge":                100,
                "parry":                100,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w彷佛如地狱幽灵般，一招「地方九则」，突然劈至，一股寒气从$N的斧中透出！",
                "damage":               250,
                "dodge":                210,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"突然间彷佛空间被掏空般，$N手中$w化作一溜烟尘，一式「雄虺九首」使$n毫无著力感！", 
                "damage":               210,
                "dodge":                210,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        });
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)){
           return 0;
        }
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 ){
            return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if( (int)me->query("force") < 15 ){
            return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -15);
        return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 350 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "spear")
    if(victim->query_skill_mapped("spear") == "xuezhan-spear")
    if(me->query_skill("xuanyuan-axe",1) > victim->query_skill("xuezhan-spear",1)) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N招式虎虎生风，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("axe")) * 4;
    }
    return 0;
}   

void skill_improved(object me)
{
    int s;
    s = me->query_skill("xuanyuan-axe",1);
    if (s== 200 && me->query("class")=="knight") {
       tell_object(me,HIW "你望着手中的斧头，心中涌起一种莫名奇妙的感觉，\n"NOR);
       tell_object(me,HIW "要是能深入研习轩辕斧法，必定能有重大的突破！\n"NOR);
       } 
    if (s== 210 && me->query("class")=="knight") {
       tell_object(me,HIW "恭喜你，你的轩辕斧法已经登峰造极了！\n"NOR);
       }
}      

