 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl;
        int sen;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ˮ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query("class")=="mei" || me->query("class")=="huangshan")
        {
        	myexp = (int) me->query("combat_exp");
        	lvl = (int) me->query_skill("liuquan-steps", 1)/10+ 2;
        }
	else {
		myexp = (int) me->query("combat_exp")/2;
		lvl = (int) me->query_skill("liuquan-steps",1)/10;
	}
	
	yourexp = (int) target->query("combat_exp");
        msg = HIR "$Nʹ����Ȫ�����еģ���ˮ�����ݣ��ó�������Ӱ��ӰӰ����$n��" NOR;
        if( yourexp < random(myexp * lvl/3))
        {
                message_vision(msg + "\n", me, target);
                msg = CYN"���$n��$N���˸���������\n"NOR;
                message_vision(msg, me, target);
                sen = (int) target->query("sen");
                target->receive_wound("sen", sen/10, me);
                target->start_busy(2 + random(2));
        }
        else
                        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                        me->start_busy(2);
        return 1;
}      
