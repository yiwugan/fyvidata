#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name", "高级拆招卸力之法");
        set("effective_level", 200);
        set("learn_bonus", -500);
        set("black_white_ness", 0);
} 
int practice_skill(object me)
{
    return notify_fail("高级拆招卸力之法只能用学的 \n");
} 
