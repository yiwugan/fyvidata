 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra, step, n;
        extra = (int)me->query_skill("demon-blade",1);
        step = (int)me->query_skill("demon-steps",1);
		n = 4;

        if ( extra < 50) 
                return notify_fail("��ģ�������ħ������ʽ�ݻ��������죡\n");
        if ( step < 50) 
                return notify_fail("��ģ�������ħ�����˲��ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "demon-steps")
                return notify_fail("�������ħ����Ҫ������ħ�����˲�����ͣ�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
		if (me->query("class")!="bandit" || me->query_skill_mapped("force")!="demon-force") {
            
			step = step/2;
			n = 5;
		}

        me->add_temp("apply/attack",step);
//        me->add_temp("apply/damage",extra);     
        msg = HIB  "$N"+HIB"������ͨ������������ħ������ʽ��һ���ǳɣ�\n\n"NOR;
		msg += HIW "����ħ���ѡ�    "+HIR"��ն������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIW  "��ħ�����ɡ�    "+HIR"��ɢ������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIW  "��ħ��է�֡�    "+HIR"����������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIW  "����ħ����    "+HIR"����������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIW  "��������ħ��    "+HIR"����������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIW  "����ħ���족    "+HIR"���á�����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIW  "����ħ���֡�    "+HIR"��ɨ������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);

        msg = HIW  "����ħ���ڡ�    "+HIR"��ɱ������" NOR;
        me->add_temp("apply/attack",step);
        me->add_temp("apply/damage",extra);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-step*2);
        me->add_temp("apply/damage",-extra);    
	
	if (me->query("combat_exp")<=1500000) n=3;
        me->start_busy(n);
        return 1;
}     
