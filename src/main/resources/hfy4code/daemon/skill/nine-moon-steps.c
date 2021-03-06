 // nine-moon-steps.c
inherit SKILL;
void setup(){
        set("name", "九阴身法");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("skill_class", "shenshui");
        set("effective_level", 150);
        set("learn_bonus", 10); 
        set("practice_bonus", -15);
        set("dodge_msg", ({
                "$n一招「阴差阳错」轻轻巧巧地避了开去。\n",
                "只见$n身影一晃，一式「阴风拂面」早已避在七尺之外。\n",
                "$n使出「阴动阳随」，轻轻松松地闪过。\n",
                "$n左足一点，一招「阴气冲天」腾空而起，避了开去。\n",
                "可是$n使一招「阴阳交错」，身子轻轻飘了开去。\n",
                "$n身影微动，已经藉一招「阴鬼叛阎」轻轻闪过。\n",
                "但是$n一招「阴气森森」使出，早已绕到$N身後！\n"
        }) );
} 
int valid_learn(object me)
{
//        if( (string)me->query("gender") != "女性" )
//                return notify_fail("九阴身法是只有女子才能练的武功。\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练九阴身法。\n");
        if (me->query_skill("nine-moon-steps",1)>= 2*me->query_skill("nine-moon-force",1)){
                        return notify_fail("你的九阴心经火候不够。\n");
        }        
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 3 ){
                return notify_fail("你的气或内力不够，不能练九阴身法。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -3);
   return 1;
}     
