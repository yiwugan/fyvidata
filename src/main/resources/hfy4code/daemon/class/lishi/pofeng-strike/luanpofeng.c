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
                return notify_fail("�����÷��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        extra = me->query_skill("pofeng-strike",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N˫��Ѫ�죬��ָ�������������Ʒ��ƿն�����������������Ѹ���ޱȵػ���$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(2);
        return 1;
}      
