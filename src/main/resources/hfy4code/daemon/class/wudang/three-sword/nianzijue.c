#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int your_exp,n;
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("��ճ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
    
    msg = "$N"+CYN"ʹ�����Ž����еġ�ճ���־�����ͼ����"NOR+"$n"+CYN"�Ĺ��ƣ�";
    me->start_busy(1);
    
    if (me->query("class")=="wudang" || me->query("combat_exp")<500000) your_exp =  (int)target->query("combat_exp")/3; 
        else  your_exp = (int)target->query("combat_exp")/2; 
    
    if(random(me->query("combat_exp")+me->query("combat_exp")/3) > your_exp)
    {
        msg += "���$p"+CYN"��$P"+CYN"���˸����ֲ�����\n" NOR;
        message_vision(msg, me, target);
        n= random(me->query_skill("three-sword", 1) / 40) + 2;
        if (n>3) n=3;
        if (me->query("class")=="wudang") target->start_busy(n);
                else target->start_busy(2);
    } else {
        msg += "����$p"+CYN"������$P"+CYN"����ͼ����û���ϵ���\n" NOR;
        message_vision(msg, me, target);
    }
    return 1;
}   
