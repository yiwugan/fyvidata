#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;
        
        if( (int)me->query_temp("charmup") ) 
                return notify_fail("���Ѿ��������䣬��������ˡ�\n");
        
        if( target != me ) return 
                notify_fail("��ֻ�����޿����������Լ���������\n");
        
        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("�޿�������ֻ��Ů�Ӳ��������ڹ���\n");
        
        skill= me->query_skill("ghosty-force",1);
        if (skill<100)
                return notify_fail("����޿���������������\n");
        if( (int)me->query("force") < 200 )     
                return  notify_fail("�������������\n");
        
        if( (int)me->query_temp("charmup") ) 
                return notify_fail("���Ѿ��������䣬��������ˡ�\n");
        
        me->add("force", -200);
        
        skill=skill/15;
        me->add_temp("apply/personality",skill);
        me->set_temp("charmup",1);
        
        message_vision(HIM "$N���۹������룬ɢ����һ�������޷����ܵ�����������\n" NOR, me);
            
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,skill:), skill*4);
        if(me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void remove_effect(object me,int extra)
{
        me->add_temp("apply/personality", -extra);
        me->delete_temp("charmup");
        message_vision(HIW"$N������ָ������������Ѿ��ص�������״̬��\n"NOR,me);
        
} 
