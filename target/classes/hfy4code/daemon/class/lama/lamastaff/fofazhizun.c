 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, level, dam, n, t;
        object weapon;

        if (me->query("class")!="lama") return notify_fail("�۷������ֻ���ɴ����µĸ�ɮ������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        
        extra = (int)me->query_skill("lamaism",1);
        level = (int)me->query_skill("lamastaff",1);
		dam = extra/2 + level/2;
		n = 1;
		t = 2;
		if( level < 50 ) return notify_fail("��������ȷ��������\n");
        if( extra > 140 ) n = 2;
                        
        msg = HIR"$N����˫�ۣ�Ĭ��𷨡�����\n$NͻȻ����˫�ۣ���ȵ�����ɱֹɱ��������\n"NOR;
        message_vision(msg, me, target);
		if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")*2/3) {
                message_vision(HIB"$N��ͷһ�𣬲����ľ�������\n",target);
				target->receive_damage("sen", extra, me);
				if (!target->is_busy()) 
                            target->start_busy(n);
		}
		else{
				message_vision(CYN"����$N����Ϊ������\n"NOR,target);
		}

        me->add_temp("apply/attack", level/2);
        me->add_temp("apply/damage", dam/2);
        msg = HIR  "$N������"+ weapon->name() +HIR"������գ�˫����ϣ����������дʡ�����\n"+HIB"$N��"+ weapon->name() +HIB"�ݺ�����$n��"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -level/2);
        me->add_temp("apply/damage", -dam/2);

        if ((int)me->query_skill("lamastaff",1) > 80) {       
				me->add_temp("apply/attack", level/2);
				me->add_temp("apply/damage", dam);
				msg = HIB  "$N��"+ weapon->name() +HIB"������һȦ����ɨ$n��"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/attack", -level/2);
				me->add_temp("apply/damage", -dam);
		}

				
		if ((int)me->query_skill("lamastaff",1) > 140) {       
				me->add_temp("apply/attack", level);
				me->add_temp("apply/damage", dam);
				msg = HIB "$N��"+ weapon->name() +HIB"������һȦ������$n��"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/attack", -level);
				me->add_temp("apply/damage", -dam);
				t = 3;
		}

		if ((int)me->query_skill("lamastaff",1) > 180) {       
				me->add_temp("apply/attack", level);
				me->add_temp("apply/damage", dam*2);
				msg = HIB "$N��"+ weapon->name() +HIB"������ת����������$n��"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/attack", -level);
				me->add_temp("apply/damage", -dam*2);
				t = 3;
		}
		if (me->query_busy()< t) 
				me->start_busy(t);
		return 1;
}     

