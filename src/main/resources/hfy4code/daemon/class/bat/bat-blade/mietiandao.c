 // mietiandao.c ���쵶
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,skill,i,n;
        object weapon;
        if (me->query("class")!="bat")
                return notify_fail("�����𵺵��Ӳ���ʹ�þ�����"RED"�����쵶��"NOR+"��\n");
        if ( (string) me->query_skill_mapped("dodge") != "meng-steps")
                return notify_fail("������"RED+"�����쵶��"NOR+"��Ҫ�ͣۻ��β�������ϲ���ʩչ��\n");
        skill = me->query_skill("bat-blade",1);
        extra = me->query_skill("blade");
		i = skill/50;
        if (skill < 150) return notify_fail("��ģ����𵶷��ݻ��������죡\n");
        if ( me->query_skill("meng-steps",1) < 150)  return notify_fail("��ģۻ��β����ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("������"RED+"�����쵶��"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("�������������������ʩչ���С�\n");
        if(userp(me) && me->query_temp("timer/shiwanshenmo") + i < time() )
                return notify_fail("������"RED+"�����쵶��"NOR+"ֻ�ܴӣ�ʮ����ħ��һʽ�б仯������\n");
				else if(me->query_busy() < 2) {
		        message_vision(HIW "\n$Nǿ���ڹ���ԭ����ɬ�����ξ�������������\n" NOR, me);				
				me->stop_busy();
		        me->add("force", -500);
				}
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        msg = HIB  "\n$Nһʽ��ʮ����ħ�ݸո�ʹ������������һ˲��ͻȻ�������µı仯��\n"HIY"$NͻȻһ��̤�������еĳ���ƾ�ջ���������Բ���������ס��$n��ͷ������$n������ä��"NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		if(random(skill/40) > 2)
		{
        message_vision(HIW "\n$NͻȻ�������ػ�Ӱ������˷����ߣ�$n����ʧ���¾���ȫ�������ܣ�\n" NOR, me ,target);
        if (target->query_busy()<3) 
                target->start_busy(3);
		}
		if( n < 200)
		n = random(skill/60);
		else n = random(skill/50);
		msg = HIR "$N�������֣�ֱ����$n������֮�У�����$w"HIR"���������°�ն�䣡" NOR;
        me->add_temp("apply/attack",extra*n);
        me->add_temp("apply/damage",extra*n);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra*n);
        me->add_temp("apply/damage",-extra*n);

		msg = HIC "$N�����⶯�����ƻ�����$w"HIC"����������׹�أ����ư�����һȥ��ǧ��㹥��$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}