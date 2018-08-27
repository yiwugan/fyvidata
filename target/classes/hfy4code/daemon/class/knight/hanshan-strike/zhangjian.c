#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,bonus, exp_bonus;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        extra = me->query_skill("hanshan-strike",1) ;
        if( extra < 90) return notify_fail("��ģۺ�ɽ�Ʒ��ݻ�����������\n");
        
//        bonus=extra/3;
        bonus=extra;
        
        exp_bonus= me->query("combat_exp")/1000*extra/5000;
        if (exp_bonus>extra) exp_bonus=extra;
        
        bonus = bonus + exp_bonus;
        
        
        
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        msg = HIM  "$N˫�ƻ��ཻ��ͻһ����˫�ֻ���Ϊ������$n"NOR+HIM"��ȥ��" NOR;
        COMBAT_D->do_attack(me,target,  TYPE_PERFORM,msg);
        msg = HIY  "$Nһ����һ��ײ��$n"NOR+HIY"�����ţ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if (extra>110) {
        msg = HIW  "$N��һ����˫�Ƽ���$n"NOR+HIW"��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (extra>150) {
        msg = HIR  "$N���ֺ��أ����ֺ�һ���ƣ������Ѿõģ��ƽ����ƿ���$n"NOR+HIR"��ȥ��" NOR;
        me->add_temp("apply/attack", bonus*2);
        me->add_temp("apply/damage", bonus*2);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -bonus*2);
        me->add_temp("apply/damage", -bonus*2);
        }
        me->add_temp("apply/attack", -bonus);
        me->add_temp("apply/damage", -bonus);
        if (extra>130) {
                if (me->query_busy()<3) me->start_busy(3);
                }
                else {
                        if (me->query_busy()<2) me->start_busy(2);
                        }
        return 1;
}      
