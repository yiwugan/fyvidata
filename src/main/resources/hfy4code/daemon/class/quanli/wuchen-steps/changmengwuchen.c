 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        extra = me->query_skill("wuchen-steps",1); 
        if ( extra < 50) return notify_fail("��ģ��޳������ݻ��������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("�۳����޳���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if(target->is_busy()) 
                return notify_fail(target->name()+"�Ѿ�æ��ʧ�룡\n"); 
 
        message_vision( HIY "$N"+HIY"��̤�˷���Ŀ�����ܣ���������֮����\n" NOR ,me,target); 
 
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")/5) 
 
        { 
        message_vision( HIY "���$N"+HIY"���Եò�֪����\n" NOR,target); 
        target->start_busy(2); 
        } 
 
        else{ 
        message_vision( HIW "��ϧ$n"+HIW"������$N"+HIW"���޳�����$Nֻ����;���У�\n" NOR,me,target); 
        me->start_busy(1);
        } 
        return 1; 
} 
