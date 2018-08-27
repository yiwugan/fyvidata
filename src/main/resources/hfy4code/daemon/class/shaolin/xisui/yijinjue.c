 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount); 
int perform(object me, object target)
{
        string msg;
        int amount;
        
        if( !target ) target = me; 
        if((int)me->query_skill("xisui",1) < 120 )
                return notify_fail("���ϴ�辭�����ߣ�\n");
        if( !target || target != me)
                return notify_fail("�׽��ֻ�������Լ����ϡ�\n");
        if( (int)target->query_temp("xisui") ) 
                return notify_fail("���Ѿ���ʩչ�׽���ˡ�\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ������\n");
        
        me->receive_wound("kee", 100);
        msg = HIC "$N��������������������죬���ξ�Ȼ�ߴ���һ�أ���\n\n" NOR;
        message_vision(msg,me);
        
        amount = me->query_str()/10;
        
        me->add_temp("apply/strength", amount);
        me->set_temp("xisui",1);
        me->start_busy(2);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,amount:), me->query_skill("xisui",1)); 
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->delete_temp("xisui");
        tell_object(me, "���˹���ϣ��ָ�������\n");
        me->add_temp("apply/strength",-amount);
}  
