 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int ap,dp;
        int base;
        extra = me->query_skill("xueyeqianzong",1);
        if ( extra < 50) return notify_fail("��ģ�ѩҰǱ�٣ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۻ��Σ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        message_vision(HIB"$N"+HIB"��Ȼ�����ת��$n"+HIB"��һ���ɣ�$N"+HIB"����Ӱ�Ѿ��ɿ���Զ��Ʈȥ�� \n"NOR,me,target);
        ap=(int)target->query("combat_exp");
        dp=(int)me->query("combat_exp"); 
        if (me->query("class")=="wolfmount") base=random(dp)+ dp*5/6+random(extra/50)*dp;
                else base = random(dp) + dp/2; 
        if(ap < base)
        {
        message_vision(HIG"$N"+HIG"ãȻ����$n"+HIG"Զȥ����Ӱ��һʱ��֪���ò���׷���� \n"NOR,target,me);
        me->remove_killer(target);
        target->remove_killer(me);
        me->start_busy(1);
        }
        else{
        me->start_busy(1);
        message_vision(HIR"$N"+HIR"ʶ����$n"+HIR"�Ļ��Σ���׼$n"+HIR"��������һ���� \n"NOR,target,me);
        COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
        }
        return 1;
}     
