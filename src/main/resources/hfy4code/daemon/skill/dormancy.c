 // dormancy.c
#include <ansi.h> 
inherit SKILL; 
void setup() {
        set("name", "������");
        set("type", "knowledge");
        set("effective_level",50);
}   
void skill_improved(object me)
{
        int s;
        s = me->query_skill("dormancy", 1);
        if( s%10==9 && (int)me->query("tol") < s/5) {
                tell_object(me, HIW "��������ѧ�������������������ˡ�\n" NOR);
                me->set("tol",(s+1)/5);
        }
        if (s==179 && !me->query("marks/dormancy")) {
                me->add("max_force",150);
                me->set("Add_force/dormancy",150);
                me->add("marks/dormancy",1);
                tell_object(me,HIR"�������������!\n"NOR);
        }
        if (s==189 && me->query("marks/dormancy")<2) {
                if (me->query("class")=="legend") {
                        me->add("max_force",200);
                        me->set("Add_force/dormancy",350);
                }       else {
                        me->add("max_force",50);
                        me->set("Add_force/dormancy",100);
                        me->set("tiexue_once",1);
                }       
                me->add("marks/dormancy",1);
                tell_object(me,HIR"�������������!\n"NOR);
        }
        if (s==199 && me->query("marks/dormancy")<3) {
                if (me->query("class")=="legend") {
                        me->add("max_force",300);
                        me->set("Add_force/dormancy",650);
                } else  {
                        me->add("max_force",100);
                        me->set("Add_force/dormancy",200);
           }
                me->add("marks/dormancy",1);
                tell_object(me,HIR"�������������!\n"NOR);
        }               
}       
