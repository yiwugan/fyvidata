 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
//      if(me->query("class")!="shenshui")
//              return notify_fail("ֻ����ˮ�����Ӳ���ʹ�������������ľ�����\n"); 
        extra = me->query_skill("nine-moon-steps",1);
        if ( extra < 30) return notify_fail("��ģ۾������ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
        
        message_vision(HIM"$N�Ų�������������$nת����ͣ��\n"NOR,me,target);
        if(random((int)target->query("combat_exp")*2) < (int)me->query("combat_exp")+extra*extra*extra)
        {
                message_vision(YEL"        ���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n"NOR,target);
                target->start_busy(2+random(extra/60));
        }
        else{
        message_vision(BLU"       ���$N�Լ�ת�˸�ͷ���ۻ���\n"NOR,me);
                if(me->query("class")!="shenshui") me->start_busy(2);
                else me->start_busy(1);
        }
        return 1;
}   
