 // incarnation.c
inherit SKILL;
#include <ansi.h>
void setup(){
        set("name", "������");
        set("usage/literate", 1);
        set("effective_level",50);
        set("skill_class",              "xianren");
        
}
void skill_improved(object me)
{
    int s; 
    s = me->query_skill("incarnation", 1);
    if( s%10==9 && (int)me->query("spi") < s/5) {
        tell_object(me, HIW "����������������������������ˡ�\n" NOR);
//      me->add("spi", 2);
        me->set("spi",(s+1)/5);
    }
}    
