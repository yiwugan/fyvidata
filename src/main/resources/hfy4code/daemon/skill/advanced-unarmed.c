#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name", "高级扑击格斗之技");
        set("effective_level", 200);
        set("learn_bonus", -500);
        set("black_white_ness", 0);
} 
int practice_skill(object me)
{
    return notify_fail("高级扑击格斗之技只能用学的 \n");
} 
