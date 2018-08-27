 // chansi.c
//written by kouga
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        string msg;
        skill = me->query_skill("tie-steps", 1);
        if(skill < 50) 
                return notify_fail("�����Ѫʮ����̫���ˣ�\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۲�˿�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        if( (int)me->query("force") < 100 )    
                return notify_fail("�������������\n");
        if( (int)target->query_temp("chansi") ) 
                return notify_fail("���Ѿ���ʩչ�۲�˿�ƣ��ˡ�\n");
        
        message_vision(HIR "$N"+HIR"����һԾ�������������ݰ�����$n"+HIR"�������ת����ͣ��\n" NOR, me,target);  
        if((int)target->query("combat_exp") < random((int)me->query("combat_exp")*skill/4))
        {
                if (userp(me))  me->add("force", -100);
                message_vision( HIR
                "$n"+HIR"��������$N"+HIR"��Ӱ�죬�����ɬ������\n" NOR, me,target);
                target->add_temp("apply/dodge", -skill);
                target->add_temp("apply/parry",-skill);       
                target->set_temp("chansi", 1);
                target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
-skill :), skill/5);
                me->start_busy(1);
        }
        else
        {
           msg = WHT"��ϧ$N"+WHT"������$n"+WHT"��������$n"+WHT"ѸȻ������"NOR;
                COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
                me->start_busy(1);
        }
        return 1;
} 
void remove_effect(object target, int amount)
{
        target->add_temp("apply/dodge", - amount);
        target->add_temp("apply/parry",- amount);
        target->delete_temp("chansi");
        message_vision("$N���ڰ����ˣ۲�˿�ƣݵ�Ӱ�졣\n",target);
}
      
