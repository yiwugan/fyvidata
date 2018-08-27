 // sword.c
#include <ansi.h> 

inherit SKILL; 
void setup() {
        set("name", "短兵刃");
        set("effective_level",          50);
        set("learn_bonus", 5);
        set("practice_bonus", 5);
}   
void skill_improved(object me)
{
        int s; 
        int m;
        s = me->query_skill("dagger", 1);
        m = me->query("mark/cor",1);
        if( ( s == 200 ) && ( m < 1 ) )  {
                tell_object(me, HIW"由於你的武艺修为有所提高，你顿时胆识大增。\n" NOR);
                me->add("cor", 2);
                me->add("tol", 2);
                 me->set("mark/cor",1);
                //me->set("con",(s+1)/5);
        }
         if( ( s == 300 ) && ( m < 2 ) ) {
                tell_object(me, HIW"由於你的武艺修为有所提高，你顿时胆识大增。\n" NOR);
                me->add("cor", 3);
                me->add("tol", 3);
                 me->set("mark/cor",2);
                //me->set("con",(s+1)/5);
        }
}