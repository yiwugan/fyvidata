 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int myexp,yourexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("wind-blade",1);
		if( extra < 120) return notify_fail("��ġ�ӭ��һ��ն�����������죡\n");
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

		message_vision(HIW"$N���ƴ��ǣ����е�"+ weapon->name() +HIW"�ó����쵶�ơ�\n"NOR, me);
//		yourexp = random( target->query("combat_exp") );
		yourexp = target->query("combat_exp");
		myexp = me->query("combat_exp")*(extra/220);
		if( yourexp < myexp )
        {
                message_vision(HIY"$N"+HIY"���������������𣬲��ɵ��ľ�������\n"NOR,target);
                if(target->query_busy()<3) target->start_busy(3);
        }
        else{
        message_vision(YEL"����$N"+NOR YEL"����Ϊ$n"+NOR YEL"������������\n"NOR, target, me);
        }
		extra = me->query_skill("blade");
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra*3);
        msg = HIW"ֻ��$N��"+weapon->name() +HIW"���Ƶ��ƣ�����������ػ���$n��"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra*3);
        if (me->query_busy()<2) 
                me->start_busy(2);
        return 1;
}    
