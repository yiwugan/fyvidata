 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        object weapon, ob; 
        if (me->query("class")!="quanli")
                return notify_fail ("��Ƽˮ����ֻ�в�������ֵܽ��ò���ʹ�á�\n");
        extra = me->query_skill("yuping-dagger",1); 
        if ( extra < 50) return notify_fail("��ģ���ƽ�̱��Уݻ��������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("��Ƽˮ����ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon"); 
		ob = target->query_temp("weapon");
        msg = HIG "$N"+HIG"�ᵶһ�������쳤̾�������δ�����ꡣ����\n";
		if (random(extra)>50 && me->query_skill_mapped("dodge") == "wuchen-steps" && target->query_temp("weapon") != 0
			&& (ob->query("skill_type") == "staff" || ob->query("skill_type") == "spear" || ob->query("skill_type") == "hammer" || ob->query("skill_type") == "axe"))
		{
			msg += HIR"\n$N"+HIR"��̤�޳������Զ̿˳���ͻ��$n"+HIR"��������\n"NOR;
			me->add_temp("apply/attack", extra*8); 
			me->add_temp("apply/damage", extra*8); 
			me->set_temp("yuping",1);
		} 
		message_vision(msg,me,target); 
        me->add_temp("apply/attack", extra*5); 
        me->add_temp("apply/damage", extra*5); 
		msg = HIC "��Ƽ���־������е�" + weapon->name() + HIC "��Х���綾�߰����$n"+HIC"��ȥ��" NOR;  
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIC "��ˮ���־���ֻ��"+ weapon->name()+ HIC "�ڿ���һת���������ԣ�ֱָ$n"+HIC"����磡" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIC "���ࡹ�־���$N"+HIC"Ծ��һ����"+ weapon->name()+ HIC "������𣬿���$n"+HIC"�Ĵ��ȣ�" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIC "���꡹�־���$N"+HIC"��ʽδ����Ȼͼ��ذ�֣�����"+ weapon->name()+ HIC "ֱ��$n"+HIC"���ؿڣ�" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
        me->add_temp("apply/attack", -extra*5); 
        me->add_temp("apply/damage", -extra*5);
		if (me->query_temp("yuping")) {
			me->add_temp("apply/attack", -extra*8); 
			me->add_temp("apply/damage", -extra*8);
			me->delete_temp("yuping");
		}

        if(me->query_busy()<3) me->start_busy(3); 
        return 1; 
} 
