 // literate.c
#include <ansi.h> 
inherit SKILL;
void setup() {
        set("name", "����ʶ��");
        set("type", "knowledge");
        set("effective_level", 50);
        set("learn_bonus", 20);
} 
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("literate", 1);
        if( s%10==9 && (int)me->query("int") < s/5 && (int)me->query("int") < 30) {
                tell_object(me, HIW "��������ѧ����������������ˡ�\n" NOR);
                me->set("int",(s+1)/5);
//              me->add("int", 2);
        }
        if(s==149)
                tell_object(me,HIW"��������Ѿ�������ͨ������ʶ��������ˡ�\n"NOR);
}    
