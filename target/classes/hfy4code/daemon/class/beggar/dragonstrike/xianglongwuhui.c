 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,n;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������޻ڡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int) me->query_skill("dragonstrike",1);
        msg = HIR "\n$N���һ����ʹ��������ʮ���ơ����һ�� "+HIY"�����޻�"+HIR" ����$n��\n" NOR;
        if(yourexp < random(myexp*(2+lvl/20)))  {
                if( random(2)&& !target->is_busy())     {
                        message_vision(msg, me, target);
                        msg = HIW"���$n�����˸���æ���ң�\n"NOR;
                        message_vision(msg, me, target);
                        target->start_busy(2);
                } else  {
                        me->add_temp("apply/attack",lvl);
                        me->add_temp("apply/damage",lvl);
                        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                        me->add_temp("apply/attack",-lvl);
                        me->add_temp("apply/damage",-lvl);  
                }
        } else  {
                me->add_temp("apply/attack",lvl/2);
                me->add_temp("apply/damage",lvl);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-lvl/2);
                me->add_temp("apply/damage",-lvl);
        }
        if ((int) me->query_skill("dragonstrike",1)>155 && me->query("class")=="beggar") 
                {       
                        me->add_temp("apply/attack",lvl);
                   me->add_temp("apply/damage",lvl*2);
                        msg=HIR "\n$N"+HIR"��������ʮ��ʽ�ڻ��ͨ���ó�ʮ�˸���Ӱһ������$n"+HIR"�ĸ���Ҫ����\n"NOR;
                        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
                        me->add_temp("apply/attack", -lvl);
                        me->add_temp("apply/damage",-lvl*2);    
                }
        if ((int) me->query_skill("dragonstrike",1)>179 && me->query("class")=="beggar") 
                {       
                        me->add_temp("apply/attack",lvl);
                   me->add_temp("apply/damage",lvl*2);
                        msg=HIR "\n$N"+HIR"�����Ķ����������ƣ����һ����"+HIW"�Ʒ����𡫡�����ʮ���ơ���\n"NOR;
                        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
                        me->add_temp("apply/attack", -lvl);
                        me->add_temp("apply/damage",-lvl*2);    
                }
        if (me->query_busy()<2) 
                me->start_busy(2);
        return 1;
}
