 inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name", "ҩ��");
        set("effective_level", 50);
        set("learn_bonus", -50);
        set("practice_bonus", -100);
}  
void skill_improved(object me)
{
        int s;
        s = me->query_skill("herb", 1);
        if (s>100) 
        if( s%10==9 && (s-99)/10>me->query("marks/resistance")) {
                tell_object(me, HIW 
"���������ҩ���гɣ�����˺��ĵֿ�������ǿ�ˡ�\n" NOR);
                me->add("resistance/kee", 1);
                me->add("resistance/sen", 1);
                me->add("resistance/gin", 1);
                me->add("marks/resistance",1);
        }
        if (me->query("class")=="knight"||me->query("class")=="quanli") {
        if (s==279 && !me->query("marks/resist179")){
                me->add("resistance/kee", 5);
                me->add("resistance/sen", 5);
                me->add("resistance/gin", 5);
                me->add("marks/resist179",1);
        }
        if (s==289 && !me->query("marks/resist189")){
                me->add("resistance/kee", 10);
                me->add("resistance/sen", 10);
                me->add("resistance/gin", 10);
                me->add("marks/resist189",1);
        }        
        if (s==299 && !me->query("marks/resist199")){
                me->add("resistance/kee", 20);
                me->add("resistance/sen", 20);
                me->add("resistance/gin", 20);
                me->add("marks/resist199",1);
        }        
        }
}      
