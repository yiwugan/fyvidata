 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra, myexp, hisexp;
        object weapon, myweapon; 
        if (me->query("class")!="quanli")
                return notify_fail ("�����߳�����ֻ�в�������ֵܽ��ò���ʹ�á�\n");
        extra = me->query_skill("yinshe-stick",1); 
        if ( extra < 100) return notify_fail("��ģ������ȷ��ݻ��������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("�����߳�����ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = target->query_temp("weapon");
        myweapon = me->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        
        if (hisexp>3500000) hisexp=hisexp*3;
        
        if(random(hisexp) < myexp && weapon && random(2))       {
                message_vision(HIW "\n\n$N"+HIW"���е�"NOR+ myweapon->name() +HIW"��������һ����ס$n"+HIW"���еı��У�$n"+HIW"��"NOR+ weapon->name()+  HIW"���ֶ��ɣ�\n\n" NOR, me,target);
                if( weapon->unequip()) 
                        weapon->move(environment(target));
        } else  {
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", extra*2);
                msg = HIW+ "\n\n$N"HIW"һʽ�����߳����ݣ����е�"NOR+myweapon->name()+HIW"�����߰�ֱҧ$n"+HIW"��$l��\n\n"+ NOR;
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
           me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra*2);
        }
        if (me->query_busy()<2) me->start_busy(2);
        return 1;
}    
