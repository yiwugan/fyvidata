 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷����ȣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        extra = me->query_skill("doomsteps",1);
        message_vision(HIR "$N"HIR"��һ������Ѹ���ޱȵ���$n"HIR"�߳�����һ�ȣ�\n"NOR, me, target);
        if(target->query("combat_exp") < random(me->query("combat_exp"))*extra/30) {
        msg =HIW "$N"HIW"ֻ���ö��߷�����Х��˵�������ķ����ҡ�\n" NOR;
        message_vision(msg, target);
        target->receive_damage("sen",extra+random(extra*3),me);
        COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,1);
		
		}
		else COMBAT_D->do_attack(me,target,TYPE_PERFORM);

        if (me->query_busy()<2) 
                me->start_busy(2);
        return 1;
}       
