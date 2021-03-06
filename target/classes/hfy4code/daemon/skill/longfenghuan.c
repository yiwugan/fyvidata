 // longfenghuan.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "龙凤双环");
        set("usage/hammer", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 200);
        set("practice_bonus", -5);
        set("black_white_ness", 0);
        set("skill_class", "assassin");
        set("parry_msg",  ({
        "结果$n用手中的$v格开了$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        }) );
        
        action = ({
        ([      "action":               
"$N单脚金鸡独立，缓缓展出龙凤双环的起手式「八面威风」，手中$w挥向$n的丹田！",
                "force":               500,
                "dodge":                500,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w相碰，发出＂隆隆＂声，一招「先声夺人」攻向$n$l！",
                "force":               600,
                "dodge":                600,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w凌空一挥，使出龙凤双环中的「龙飞凤舞」击向$n$l！",
                "force":               500,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「游龙在天」，$w夹杂着风声撞向$n$l！",
                "force":               800,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        });
}
int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 50 ){
                return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
        }
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 300 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "blade")
    if(victim->query_skill_mapped("blade") == "bat-blade" )
    if(me->query_skill("hammer") > victim->query_skill("blade")) {
    switch(random(3)) {
        case 0:
                message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                break;
        case 1:
                message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                break;
        case 2:
                message_vision(HIR "\n因刀锤相克，$n逐渐施展不开了！" NOR,me,victim);
                break;
                }
    return random(me->query_skill("hammer")) * 4;
    }
    return 0; 
} 
int practice_skill(object me)
{
        if (me->query_skill("longfenghuan",1) > 100)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");       
        if ((int)me->query("force") < 20) {
                return notify_fail("你的内力不够练习。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}   

void skill_improved(object me)
{
    int s;
    s = me->query_skill("longfenghuan",1);
    if (s== 150 && me->query("class")=="assassin") {
       tell_object(me,HIW "你对龙凤双环的了解有了一个飞跃！\n"NOR);
       } 
    if (s== 180 && me->query("class")=="assassin") {
       tell_object(me,HIW "你对龙凤双环的了解有了一个飞跃！\n"NOR);
       } 
    if (s== 210 && me->query("class")=="assassin") {
       tell_object(me,HIW "恭喜你，你的龙凤双环已经登峰造极了！\n"NOR);
       }
    if (s== 200 && me->query("class")=="assassin") {
       tell_object(me,HIW "你忽然觉得，如果你自己再继续钻研下去的话，\n"NOR);
       tell_object(me,HIW "才能够真正领略到龙凤双环的精髓！\n"NOR);
       } 
}      
