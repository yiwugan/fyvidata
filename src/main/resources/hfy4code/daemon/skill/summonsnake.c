#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                             "驱蛇阵法");
        set("type",                             "knowledge");
        set("learn_bonus",                      -100);
        set("practice_bonus",           -100);
        set("black_white_ness",         -100);
        set("effective_level",          100); 
} 
int valid_learn(object me)
{
        if( (int)me->query_skill("huntunforce",1) < (int)me->query_skill("summonwolf",1)) {
                return notify_fail("你的混沌心法不够精纯，无法更好地把控驱蛇之术。\n");
        }
        return 1;
} 
void skill_improved(object me)
{
    int s;
    s = me->query_skill("summonwolf", 1);
    if (s== 150 && me->query("class")=="beggar") {
       tell_object(me,HIW "你对驱蛇阵法的了解有了一个飞跃！\n"NOR);
       tell_object(me,HIW "你可以驱动更多的蛇了！\n"NOR);
       } 
    
} 
