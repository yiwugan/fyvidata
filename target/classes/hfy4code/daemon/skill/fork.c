 // fork.c
#include <ansi.h> 

inherit SKILL; 
void setup(){
        set("name", "�����淨");
        set("effective_level",          50);
        set("learn_bonus", 20);
}     
void skill_improved(object me)
{
        int m,s; 
        s = me->query_skill("fork", 1);
        m = me->query("mark/cor",1);
        if( ( s == 200 ) && ( m < 1 ) )  {
                tell_object(me, HIW"������������Ϊ������ߣ����ʱ��ʶ������\n" NOR);
                me->add("cor", 2);
                me->add("tol", 2);
                 me->set("mark/cor",1);
                //me->set("con",(s+1)/5);
        }
         if( ( s == 300 ) && ( m < 2 ) ) {
                tell_object(me, HIW"������������Ϊ������ߣ����ʱ��ʶ������\n" NOR);
                me->add("cor", 3);
                me->add("tol", 3);
                 me->set("mark/cor",2);
                //me->set("con",(s+1)/5);
        }


}