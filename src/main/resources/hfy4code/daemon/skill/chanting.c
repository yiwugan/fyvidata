 // chanting.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                             "�о�");
        set("learn_bonus",                      -15);
        set("practice_bonus",           -5);
        set("effective_level",          50);
        set("black_white_ness",         50);
        set("type",                                     "knowledge");
        
} 
void skill_improved(object me) {
        int s;
        
        s = me->query_skill("chanting", 1);
        if(s%10==9 && (int)me->query("cps") < s/5) {
                tell_object(me, HIW "�������о������гɣ���Ķ��������ˡ�\n" NOR);
                me->set("cps",(s+1)/5);         
//              me->add("cps", 2);
        }
}      
