 // SFY@FY4
//mod by ice@fy4
//update by xiaolang,�޸�������cancel busy������busyʧ�ܵ�bug
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    string msg;
    int extra, myexp, yourexp, cpexp, busy;
	  int busytime;
    if(me->query("class")!="mei")
        return notify_fail("ֻ���ɹ��ֵ�ʥŮ�����������İ������\n");
    if( me->query_skill("xuanxinjue", 1) < 70 )
        return notify_fail("������İ���������ߣ�\n");
    
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n"); 
    if((int)me->query("mana") < 80 )
        return notify_fail("��ķ���������\n"); 
    if((int)me->query("sen") <= 50 )
        return notify_fail("��ľ���û�а취��Ч���У�\n"); 
    me->add("mana", -80);
    me->receive_damage("sen", 50);
    
    msg = HIW "\n$N"HIW"���һ��������-��-��-��  ��-��-��-������ һ������ľ�����$n"HIW"������\n"NOR ;
    
    extra = me->query_skill("spells");
	myexp = me->query("combat_exp");
    cpexp=myexp+ random(myexp/7) + random((extra-70)*extra/7*extra+7);
    //cpexp=myexp/2 + (2+extra/120)*random(myexp)/2;
    yourexp = target->query("combat_exp");

    if( cpexp > yourexp) {
        msg +=HIC"$n"HIC"�����ƶ���һ������ľ������ѷ�����·��$n"HIC"��ʱ�������ã�\n";
		message_vision(msg+NOR, me, target);
		busytime = 3+extra/100;
		busy = target->query("no_busy");
		target->delete("no_busy");
        target->start_busy(busytime);//by xiaolang
		if(busy) target->set("no_busy", busy);
        target->start_call_out( (: call_other, __FILE__, "remove_effect",target :), busytime);
     } else  {
		 msg += YEL"���Ǳ�$n"NOR YEL"�㿪�ˡ�\n";
		 message_vision(msg+NOR, me, target);
		 if(me->query_busy()<2) me->start_busy(2);
	 }
    return 1;
} 
 
void remove_effect(object target)
{
        message_vision(HIR "\n$N"HIR"���ڴ����εľ���������������\n" NOR, target);
}      