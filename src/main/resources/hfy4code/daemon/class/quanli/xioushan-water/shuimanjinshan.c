 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int myexp,yourexp,extra,lvl;
        
        extra = me->query_skill("xioushan-water",1)*2; 
        if ( extra < 100) return notify_fail("��ģ���ɽ��ˮ���ݻ��������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("��ˮ����ɽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        me->add_temp("apply/attack",extra); 
        //me->add_temp("apply/damage", extra); 
        msg = HIW  "$N"+HIW"�����糤�����ˣ���������ٺ�գ�����ͻȻ���һƬˮ����ֱ��$n��" NOR; 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -extra); 
        //me->add_temp("apply/damage", -extra); 
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int) me->query_skill("unarmed") / 50 + 1;
        if (me->query("class")!="quanli")
                lvl = 2;
        if( random(myexp +yourexp) < myexp*lvl )
        {
                msg = HIG  "\n$N"+HIG"˳���ٴ��ھ���ˮ��������ɢ�����ˮ������������������$n��" NOR; 
                message_vision(msg + "\n", me, target);
                msg = "���$n��$N���˸���æ���ң�\n";
                message_vision(msg, me, target);
                target->start_busy(3);
                me->start_busy(3);
        }else{
                me->start_busy(2); }
        return 1; 
}    
