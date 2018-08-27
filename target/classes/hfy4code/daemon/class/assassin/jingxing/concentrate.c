#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount); 
int exert(object me, object target, int amount)
{
        int skill;
        skill = me->query_skill("jingxing",1); 
        if (me->query("class")!="assassin")
                return notify_fail ("�����ֻ�н�Ǯ�������ʹ�á�\n"); 
        if(skill < 150) 
                return notify_fail("��ľ����ķ�̫���ˣ�\n");
        if (me->query("combat_exp")<4000000)
                return notify_fail("���ս�����鲻�㣬���������������\n");
                
        if( target != me ) 
                return notify_fail("�����ֻ��ʩ��������\n");
                
        if( (int)me->query("force") < 200 )   
                return  notify_fail("�������������\n");
        if( (int)me->query_temp("jingxing/concentrate") ) 
                return  notify_fail("���Ѿ����˹����ˡ�\n");
        
        me->add("force", -200);
        message_vision(HIR "$N�����������ϡ�����Ϣ�����������������ƻ�����һ��������\n" NOR, me);
        me->set_temp("jingxing/concentrate", 1);
        me->add_temp("apply/attack",skill/5);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,skill :), skill);
        me->start_busy(1);
        return 1;
}   
void remove_effect(object me, int skill)
{
        me->delete_temp("jingxing/concentrate");
        me->add_temp("apply/attack",-skill/5);
        tell_object(me, "��ľ����������ϣ��������ջص��\n");
}
       
