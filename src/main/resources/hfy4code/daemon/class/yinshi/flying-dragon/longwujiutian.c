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
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        extra = me->query_skill("flying-dragon",1);
        if( extra <=20) return notify_fail("��ķ���̽���ֻ�����������\n");
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N˫�ֳ�ӥצ״��ȫ���ڿգ������ƴ��巭�ɣ�����$nץȥ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        if (me->query_busy()<2) me->start_busy(2);
        if (random((int)target->query("combat_exp")*2) < (int)me->query("combat_exp") && target->query_busy()<2 ) target->start_busy(2);
        return 1;
}  
