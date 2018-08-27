#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
        int skill;
        skill = me->query_skill("jingxing",1); 
        if (me->query("class")!="assassin")
                return notify_fail ("������ֻ�н�Ǯ�������ʹ�á�\n"); 
        if( skill < 150) 
                return notify_fail("��ľ����ķ�̫���ˣ�\n");
        
        if (me->query("combat_exp")<3000000)
                return notify_fail("���ս�����鲻�㣬��������ᾲ������\n");
                                
        if( target != me ) 
                return notify_fail("���ľ�ֻ��ʩ��������\n");
        if( (int)me->query("force") < 200 )   
                return  notify_fail("�������������\n");
        if( (int)me->query_temp("jingxing/persist")) 
                return  notify_fail("���Ѿ����������Ƶ��ڹ��ˡ�\n");
        
        me->add("force", -200);
        message_vision(YEL "$N�������ɣ����𡰾������������п����γ����겻�ڵ��������Ρ�\n" NOR, me);
        call_out("fillup",10,me,10,0,skill*4);        
        me->set_temp("jingxing/persist", 1);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void fillup (object me, int total, int count, int amount)
{
        if(++count>=total)
        {
                tell_object(me,WHT"��ľ�������ת��ϣ�����Ϣ�ջص��\n"NOR);
                me->delete_temp("jingxing/persist");
                return;
        }
        else {
                if (me->query("force")<me->query("max_force"))
                        me->add("force",amount);
                tell_object(me,GRN"��ֻ����������һ��������ů��������\n"NOR);
           call_out("fillup",10,me,total,count, amount);
        }
        return ;
}    
