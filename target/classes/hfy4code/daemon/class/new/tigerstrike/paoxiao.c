#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, exp_bonus, extra_dam;
        
        if( !target ) target = offensive_target(me);
        extra = me->query_skill("unarmed")*2/3;
//        if(extra <= 1 ) return notify_fail("��ġ����ǰ���ȭ������������\n");
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        msg = HIY "$N����������������һ��������˫�ֻ���Ϊצ�����������Ҫ��$n˺�����룡\n" NOR;
        exp_bonus = (me->query("combat_exp")/1000)*extra/9000;
        if (exp_bonus>extra/3) exp_bonus = extra/3;     
        
        if (me->query("class")=="wolfmount" && me->query("timer/wolf-strike")+4>time()) {
                extra_dam = extra*2/5;
        }
        
        me->add_temp("apply/damage",extra_dam);
        me->add_temp("apply/attack",exp_bonus);
        
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        me->add_temp("apply/damage",-extra_dam);
        me->add_temp("apply/attack",-exp_bonus);
        
        if (me->query_busy()<2) me->start_busy(1); 
        
//        if (target->query_temp("damaged_during_attack")) 
//                me->set("timer/wolf-strike",time());
                
                        
        return 1;
}
