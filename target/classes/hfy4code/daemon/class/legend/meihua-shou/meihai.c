 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,extra;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��÷����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        extra= (int)me->query_skill("meihua-shou",1);
        if(me->query("class") != "legend") extra = extra/5;
        
        if (extra<20)
                 return notify_fail("���÷���ֲ���������\n");
        
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
        
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        if (target->query("boss") || target->query("big_boss")) yourexp=yourexp*17;
//      200/2+1.5x150=315/20+1= 16.75   
        lvl = (int) me->query_skill("unarmed") / 20 + 1;
        
        if(me->query("class") != "legend") lvl=lvl/2 ;
        
        msg = HIR "$N˫�ֻó�����÷������ѩ�Ƶ���$n"+HIR"������" NOR;
        if( random(myexp +yourexp) < myexp*lvl )
        {
                message_vision(msg + "\n", me, target);
                msg = "���$n��$N���˸���æ���ң�\n";
                message_vision(msg, me, target);
                target->start_busy(3);
        }
        else        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   me->start_busy(2);
        return 1;
}      
