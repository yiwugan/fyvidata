 // TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    string msg;
    int extra, yourexp, myexp, cpexp;
    
    if(!me->is_fighting())
        return notify_fail("���ź�����ֻ������ս����ʩչ��\n");
    if( !target ) target = offensive_target(me);
    if((int)me->query_skill("mapo", 1) < 100 )
        return notify_fail("������ź����������ߣ�\n");
    
    if( !target
        ||!target->is_character()
        ||target->is_corpse()
        ||target==me)
        return notify_fail("��Ҫ��˭ʩչ���������\n"); 
    if(target->query("disable_type") ==HIW "<������>" NOR)
        return notify_fail("�����ڲ�����Ҫʩչ���ź�������\n"); 
    if((int)me->query("mana") < 100 )
        return notify_fail("��ķ���������\n"); 
    if((int)me->query("sen") < 50 )
        return notify_fail("��ľ���û�а취��Ч���У�\n"); 
    me->add("mana", -100);
    me->receive_damage("sen", 50);
    
    if( random(me->query("max_mana")) < 80 )
    {
        msg = CYN"$N"+NOR CYN"Ĭ���������ʲôҲû�з�����\n"NOR;
		message_vision(msg, me, target);
		if(me->query_busy()<2) me->start_busy(2);
        return 1;
    } 
    msg = WHT "$N"+NOR WHT"Ĭ�������ʱ��������ռ�Խ��Խ�䡭��\nֻ��$N"+NOR WHT"˫��һ�ۣ��γ�һ������ĺ�������$n"+NOR WHT"������\n\n"NOR;
    
    extra = (int)me->query_skill("spells");
    yourexp=(int)target->query("combat_exp");
    myexp=(int)me->query("combat_exp");
    cpexp=(3+extra/130)*random(myexp)/2;
    if(yourexp < cpexp)
    {
        msg +=HIW"����ĺ�����Χ��$n"+HIW"��ȫ����$n"+HIW"���۳ɱ��飡\n";
        target->set_temp("disable_inputs",1);
        target->set("disable_type",HIW "<������>" NOR);
        target->set_temp("is_unconcious",1);
        seteuid(ROOT_UID);
        target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),
            3+random(extra/70)+(extra/80));
		if(me->query_busy()<1) me->start_busy(1);
	} 
	else {
		msg += HIY"���Ǳ�$n"+HIY"�㿪�ˡ�\n";
		if(me->query_busy()<3) me->start_busy(3);
	}
    message_vision(msg+NOR, me, target);
    
    return 1;
} 
void remove_frozen(object me)
{
    me->delete("disable_type");
    me->delete_temp("disable_inputs");
    me->delete_temp("is_unconcious");
    if(!me->is_ghost())
        message_vision(HIR "\n$N"+HIR"����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n" NOR, me);
	me->start_busy(1);
}      
