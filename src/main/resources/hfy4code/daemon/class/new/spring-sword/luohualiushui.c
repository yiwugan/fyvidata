#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int third_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
        string msg;
        int extra;
        int bonus, exp_bonus;
        object weapon;
        extra = me->query_skill("spring-sword",1);
        weapon=me->query_temp("weapon");
//        if ( extra < 50) return notify_fail("��Ĵ��꽣�����������죡\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���仨��ˮ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        

        msg = HIC  "\n$N"HIC"����һЦ��ʹ�����꽣���е�����һ�У������仨��ˮ�ݣ���\n\n"+HIG"���� �� �� �⡹\n$N"HIG"���е�"+ weapon->name()+  HIG"��Ȼ���������ˮ�����Ž����������裡\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIG  "���� ˮ �� �项\n����$n"HIG"�����ڽ���֮�䣬$N"HIG"��Хһ������ͷ����һ����\n" NOR;
        me->add_temp("apply/damage",extra*4);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*4);

		if(me->query("free_rain/ending") && extra > 50) {
			exp_bonus = me->query("combat_exp")/1000*extra/8000;    
			if(extra > 150) bonus = extra;
			if(extra > 180) bonus = extra*2;
			if(extra > 300) bonus = extra*5;
			me->add_temp("apply/attack",extra*4);
			me->add_temp("apply/damage",extra*8+ bonus+exp_bonus);
			msg = HIM  "$N"HIM"��������⻯�����У�������õĽ�Ӱ�紺�绯��㹥��$n��\n" NOR;
			target->receive_wound("kee",extra*3);
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			me->add_temp("apply/attack",-extra*4);
			me->add_temp("apply/damage",-extra*8-bonus-exp_bonus);
			if (me->query_busy()<3) me->start_busy(3);
		}
		else {
//            message_vision(YEL"$N"NOR YEL"�Ľ�ʽ�������ƺ���δ�黯����\n"NOR, me);
			if (me->query_busy()<2) me->start_busy(2);
		}
        return 1;
 
}
