 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, bonus;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        
        extra = me->query_skill("sword");
        bonus = me->query_skill("lefthand-sword", 1); 
        if (bonus>130) extra = extra + bonus;
        
        me->add_temp("apply/attack", bonus*2);    
        me->add_temp("apply/damage", extra*2);
        msg = HIR"$N"+HIR"��"+weapon->name() +HIR"�������֣����죬��������׼����$n"+HIR"�̳���" NOR;
		if (bonus>130) msg += HIR"\n$N"+HIR"��һ���̵ó������������󲻲�ֺ���" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -bonus*2);
        me->add_temp("apply/damage", -extra*2);
        if (me->query_busy()<2) 
                me->start_busy(2);
        return 1;
}  
