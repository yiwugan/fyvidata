 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,extra,level,myexp1;
        extra=me->query_skill("bloodystrike",1);
        if(me->query("class")!="lama" && extra<100)
                return notify_fail("�����ڴ���ӡ����Ϊ�������ߡ�\n");   
        if(extra<20)
                return notify_fail("�����ڴ���ӡ����Ϊ�������ߡ�\n");   
                if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷��ޱߣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");        
        
        myexp = (int) me->query("combat_exp");
        myexp1 = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        
        if (target->query("boss") || target->query("big_boss")) yourexp=yourexp*7; 
//      200/2+1.1*140 = 254, 254/(35+9)+1 = 6.7 
        lvl = (int) me->query_skill("unarmed") / (20+random(35)) + 1;
        level = (int) me->query_skill("unarmed") / (20+random(35)) + 1;
        if(me->query("class")!="lama") { 
        lvl = (int) me->query_skill("unarmed") / (40+random(25)) + 1;
        	}
        msg = HIR "$N"NOR+HIR"ʹ�����ڴ���ӡ�еģ۷��ޱߣݣ��ó�������Ӱ����$n��" NOR;
        if( (myexp * lvl+yourexp) > random( myexp +yourexp*lvl) )
        {
                message_vision(msg + "\n", me, target);
                msg = "���$n��$N���˸���æ���ң�\n";
                message_vision(msg, me, target);
                target->start_busy(3);
        }
        else
        {
                me->add_temp("apply/attack",extra/3);   
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
           me->add_temp("apply/attack",-extra/3);  
        }
        me->start_busy(2);
        return 1;
}       
