#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, exp_bonus, extra_dam;
        
        if( !target ) target = offensive_target(me);
        extra = me->query_skill("unarmed")*3/2;
        if(extra <= 50 ) return notify_fail("��ġ����ǰ���ȭ������������\n");
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���Ϻ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        msg = HIR "$N�����������ϣ�˫��һǰһ��ץ$n���ʺ�Ҫ��$n�ĺ��ץ�ϣ�\n" NOR;
        exp_bonus = (me->query("combat_exp")/1000)*extra/9000;
        if (exp_bonus>extra/3) exp_bonus = extra/3;     
        
        if (me->query("class")=="wolfmount" && me->query("timer/wolf-strike")+8>time()) {
                extra_dam = extra*2;
        }
        
        me->add_temp("apply/damage",extra+extra_dam);
        me->add_temp("apply/attack",extra/3+exp_bonus);
        
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        me->add_temp("apply/damage",-extra-extra_dam);
        me->add_temp("apply/attack",-extra/3-exp_bonus);
        
        if (me->query_busy()<2) me->start_busy(2); 
        
        if (target->query_temp("damaged_during_attack")) 
                me->set("timer/wolf-strike",time());
                
                        
        return 1;
}
