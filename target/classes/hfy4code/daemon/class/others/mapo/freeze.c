 // TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    string msg;
    int ap, dp,myexp;
    
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
    
    if( random(me->query("max_mana")) < 30 )
    {
        write("��ʧ���ˣ�\n");
        return 1;
    } 
    msg = HIW "$N˫��һ�ۣ��γ�һ������ĺ�������$n������\n\n" ;
    
    ap = me->query_skill("spells");
    myexp = me->query("combat_exp");
    ap = ( ap * ap /100 * ap/40 ) * (int)me->query("sen") ;
    dp = target->query("combat_exp");
    if( (random(ap + dp) > dp) && (random(myexp) > dp/3) )
    {
        msg +="����ĺ�����Χ��$n��ȫ����$n���۳ɱ��飡\n";
        target->set_temp("disable_inputs",1);
        target->set("disable_type",HIW "<������>" NOR);
        target->set_temp("is_unconcious",1);
        seteuid(ROOT_UID);
        target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),
            random((int)me->query_skill("spells")/30)+
                                ((int)me->query_skill("spells")/30));
    } else  msg += "���Ǳ�$n�㿪�ˡ�\n";
    
    message_vision(msg+NOR, me, target);
    target->kill_ob(me);
    me->start_busy(2);
    return 1;
} 
void remove_frozen(object me)
{
    me->delete("disable_type");
    me->delete_temp("disable_inputs");
    me->delete_temp("is_unconcious");
    if(!me->is_ghost())
        message_vision(HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n" NOR, me);
}      
