 // literate.c
#include <ansi.h> 
inherit SKILL;
void setup() {
        set("name", "读书识字");
        set("type", "knowledge");
        set("effective_level", 50);
        set("learn_bonus", 20);
} 
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("literate", 1);
        if( s%10==9 && (int)me->query("int") < s/5 && (int)me->query("int") < 30) {
                tell_object(me, HIW "由於你的勤学苦读，你的悟性提高了。\n" NOR);
                me->set("int",(s+1)/5);
//              me->add("int", 2);
        }
        if(s==149)
                tell_object(me,HIW"你的悟性已经不能再通过读书识字来提高了。\n"NOR);
}    
