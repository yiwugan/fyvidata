 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������-��ȸ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query("marks/super") == 0)
        {
                if((int)me->query("kee")*100/(int)me->query("max_kee") > 20
                && (int)me->query("eff_kee")*100/(int)me->query("max_kee") > 20
                && (int)me->query("sen")*100/(int)me->query("max_sen") > 20
                && (int)me->query("eff_sen")*100/(int)me->query("max_sen") > 20)
                return notify_fail("������ʹ���е�ʱ��\n");
        }
        extra = me->query_skill("unarmed") ;
         if (me->query("class")=="shaolin")  extra = extra *3/2;
        if(extra <= 200 ) return notify_fail("���½��Բ����ȭ�����������������ܳ�����-��ȸ��\n");
        msg = HIR "$N������˵������ֻ����һ���ˡ�����������$Nʹ��������һ�С�����.��ȸ��!
$nһʱ��Ϊ�Լ��ۻ�����Ȼ�����ĸ�$N����Ӱ!
$n����һ��$N�͵س���$n����ϥ����ס$n���������־�ס$n
��ͷ������������ȥ��ͬʱ�ⲿ����$n��ü�ġ�" NOR;
        weapon = me->query_temp("weapon");
        extra=extra-150;
        me->add_temp("apply/damage",extra*10);
        me->add_temp("apply/attack",extra*4);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*10);
        me->add_temp("apply/attack",-extra*4);
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}  
