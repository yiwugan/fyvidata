 // �ݺ��ĺ�
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("fengyu-piaoxiang",1);
        if ( extra < 150) return notify_fail("���ݺ��ĺ�����Ҫ150���۷���Ʈ�㲽�ݡ�\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ݺ��ĺ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                
        if(me->query_temp("zonghengsihai")+10>time())
                return notify_fail("��ո�ʩչ�����ݺ��ĺ��ݣ���\n");
        message_vision(HIY"$N"HIY"����ͻȻ�ӿ죬��ͬ�������������������ݺ��ĺ�֮���ƣ�\n" NOR,me,target);
       if(random((int)target->query("combat_exp"))*3 < (int)me->query("combat_exp")*2)
        {
                message_vision(HIB "���$N"+HIB"���ָ��ţ�һ��Īչ��\n" NOR,target);
                me->set_temp("zonghengsihai",time());
                target->start_busy(2+random(2));
        }
        else{
                message_vision("���$N�������ң�\n",target);
                me->start_busy(2);
        }
        return 1;
}  
