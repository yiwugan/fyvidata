 // force.c
#include <ansi.h> 
inherit SKILL; 
void setup() {
        set("name", "�ڹ��ķ�");
        set("effective_level",          50);
} 
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("force", 1);
        if( s%10==9 && (int)me->query("con") < s/5) {
                tell_object(me, HIW"�������ڹ������гɣ�������ʸ����ˡ�\n" NOR);
//                me->add("con", 2);
                me->set("con",(s+1)/5);
        }
} 
