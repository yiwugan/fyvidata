 // celecurse.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL; 
void setup() {
        set("name",                             "通天降");
        set("learn_bonus",                      -10);
        set("practice_bonus",           10);
        set("practice_damage",          40);
        set("black_white_ness",         0);
        set("usage/cursism",            1);
        set("effective_level",          150);
        set("skill_class",                      "yinshi");
}  
int practice_skill(object me)
{
        if (me->query_skill("celecurse",1) > 80)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");
        if((int)me->query("force") < 5 ) {
                return notify_fail("你的内力不够，不能练通天降。\n");
        }
        me->add("force", -5);
        return ::practice_skill(me);
        
        
} 
