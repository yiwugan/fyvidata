 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, level, dam, n;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������Ұ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        
        extra = me->query_skill("staff") / 4;
        level = me->query_skill("cloudstaff", 1);
        
        if (me->query("class")=="bonze") dam = extra*3/2;
                        else dam = extra;
                        
        if (level<160 && level>120 && me->query("class")=="bonze") {
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage",dam);
        msg = HIR  "$N�ͺ���ţ���������˫�ۣ����е�"+ weapon->name() +"�ó����������׷�������������һ���ǳɣ���籩���ع���$n��\n\n��һʽ��������Ұ��"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIB  "�ڶ�ʽ�������ĺ�����"NOR;    
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -dam);
                me->start_busy(3);
                return 1;
        } 
        if (level<160) {
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", dam);
        msg = HIY  "$N�ͺ���ţ���������˫�ۣ����е�"NOR+ weapon->name() +HIY"�ó�һ�����׷���������������$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
   me->add_temp("apply/damage", -dam);     
        me->start_busy(2);
        return 1;
        }
        
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage",dam);
        msg = HIR  "$N�ͺ���ţ���������˫�ۣ����е�"+ weapon->name() +"�ó����������׷�������������һ���ǳɣ���籩���ع���$n��\n\n��һʽ��������Ұ��"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "�ڶ�ʽ�������ĺ�����"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC  "����ʽ��������죡����"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -dam);
                me->start_busy(3);
                return 1;
                
}      
