 // TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    string msg;
    int ap, dp,myexp;
    
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
    
    if( random(me->query("max_mana")) < 30 )
    {
        write("你失败了！\n");
        return 1;
    } 
    msg = HIW "$N双手一聚，形成一团奇冷的寒气，向$n射来！\n\n" ;
    
    ap = me->query_skill("spells");
    myexp = me->query("combat_exp");
    ap = ( ap * ap /100 * ap/40 ) * (int)me->query("sen") ;
    dp = target->query("combat_exp");
    if( (random(ap + dp) > dp) && (random(myexp) > dp/3) && !target->query("boss"))
    {
        msg +="奇冷的寒气包围了$n的全身，将$n凝聚成冰块！\n";
        target->set_temp("disable_inputs",1);
        target->set("disable_type",HIW "<冻僵中>" NOR);
        target->set_temp("is_unconcious",1);
        seteuid(ROOT_UID);
        target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),
            random((int)me->query_skill("spells")/30)+
                                ((int)me->query_skill("spells")/30));
    } else  msg += "但是被$n躲开了。\n";
    
    message_vision(msg+NOR, me, target);
    target->kill_ob(me);
    me->start_busy(4);
    return 1;
} 
void remove_frozen(object me)
{
    me->delete("disable_type");
    me->delete_temp("disable_inputs");
    me->delete_temp("is_unconcious");
    if(!me->is_ghost())
        message_vision(HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n" NOR, me);
}      
