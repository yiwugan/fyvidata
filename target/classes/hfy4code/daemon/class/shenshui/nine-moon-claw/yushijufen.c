#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
    string msg; 
	int extra;
    if(me->query("class")!="shenshui")
          return notify_fail("ֻ����ˮ�����Ӳ���ʹ������ʯ��١��ľ�����\n"); 
    
	extra = me->query_skill("nine-moon-force",1);
    if( extra < 150)
        return notify_fail("��ľ����ľ�������������\n"); 
    if(!me->query_condition("tianyi"))
        return notify_fail("����ʯ��١�����Ҫ������һ��ˮ�Ķ��Բ���ʹ�ã���\n");
    if( !target ) target = offensive_target(me); 
    if( !target ||!target->is_character()|| !me->is_fighting(target) )
        return notify_fail("����ʯ��١�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
    msg = RED "$N"+NOR RED"�����������������Ҫ����ͬ���ھ�����˵�������Ѫ��˲ʱ�����Ϊ֮��ɫ��\n\n";
    if(me->query("combat_exp") > random(target->query("combat_exp")*40/extra) )
    {
        msg += "�����أ�$n"+NOR RED"��һƬ��ɫ��Ѫ���Χ��ʲô���������ˣ�\n"NOR;
        //target->receive_damage("kee",(int)me->query("max_kee")+1,me);
        //receive_wound("kee", ((int)me->query("max_kee")+5000),me);
        message_vision(msg, me, target);
        target->die();
        me->die();
        me->set_skill("nine-moon-force",101 + random(extra-110));
    }
    else
    {
        msg += WHT"����$n���Ƕ����$N"+NOR WHT"�����һ������"
            "$n"+NOR WHT"�����ƺ�������һ�㵭��������ɫ��\n" NOR;
        message_vision(msg, me, target);
        target->apply_condition("tianyi",50);
        me->unconcious();
    }
    
    return 1;
}    
