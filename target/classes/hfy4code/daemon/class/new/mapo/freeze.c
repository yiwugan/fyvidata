 // TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    string msg;
    int extra, yourexp, myexp, cpexp;
    
    if(!me->is_fighting())
        return notify_fail("麻婆寒练术只可以在战斗中施展！\n");
    if( !target ) target = offensive_target(me);
    if((int)me->query_skill("mapo", 1) < 100 )
        return notify_fail("你的麻婆寒练术不够高！\n");
    
    if( !target
        ||!target->is_character()
        ||target->is_corpse()
        ||target==me)
        return notify_fail("你要对谁施展这个法术？\n"); 
    if(target->query("disable_type") ==HIW "<冻僵中>" NOR)
        return notify_fail("你现在并不需要施展麻婆寒练术。\n"); 
    if((int)me->query("mana") < 100 )
        return notify_fail("你的法力不够！\n"); 
    if((int)me->query("sen") < 50 )
        return notify_fail("你的精神没有办法有效集中！\n"); 
    me->add("mana", -100);
    me->receive_damage("sen", 50);
    
    if( random(me->query("max_mana")) < 80 )
    {
        msg = CYN"$N"+NOR CYN"默念咒语，但是什么也没有发生！\n"NOR;
		message_vision(msg, me, target);
		if(me->query_busy()<2) me->start_busy(2);
        return 1;
    } 
    msg = WHT "$N"+NOR WHT"默念咒语，顿时四周丈许空间越来越冷……\n只见$N"+NOR WHT"双手一聚，形成一团奇冷的寒气，向$n"+NOR WHT"射来！\n\n"NOR;
    
    extra = (int)me->query_skill("spells");
    yourexp=(int)target->query("combat_exp");
    myexp=(int)me->query("combat_exp");
    cpexp=(3+extra/130)*random(myexp)/2;
    if(yourexp < cpexp)
    {
        msg +=HIW"奇冷的寒气包围了$n"+HIW"的全身，将$n"+HIW"凝聚成冰块！\n";
        target->set_temp("disable_inputs",1);
        target->set("disable_type",HIW "<冻僵中>" NOR);
        target->set_temp("is_unconcious",1);
        seteuid(ROOT_UID);
        target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),
            3+random(extra/70)+(extra/80));
		if(me->query_busy()<1) me->start_busy(1);
	} 
	else {
		msg += HIY"但是被$n"+HIY"躲开了。\n";
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
        message_vision(HIR "\n$N"+HIR"发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n" NOR, me);
	me->start_busy(1);
}      
