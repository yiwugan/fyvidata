 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, damage;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ħʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        extra = me->query_skill("demon-strike",1);
		if(extra < 160) return notify_fail("��ģ������ħ�������ƣݲ���������\n");
		damage = (int)me->query("max_gin")/10;
		if(me->query("class") != "bandit") damage = damage/2;
        msg = HIC "$N"+HIC"˫�۱�����һ�У���ħʽ�ݣ�˫��£��$n��" NOR;
        if(target->query("combat_exp") < me->query("combat_exp")/2 + random(me->query("combat_exp")*extra/60))
        {
        message_vision(msg+"\n",me,target);
        message_vision( CYN "$N"+NOR CYN"����������ȫ��������Ӱ��ס�� һ��������$N"+NOR CYN"������ӿ������\n" NOR,target);
        target->receive_damage("gin",damage+random(damage*2),me);
        me->receive_heal("gin",damage);
        COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,1);
        }       
        else{
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        me->start_busy(2);
        return 1;
}
