#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        string msg;
        int lvl, ap, dp;
    
//    if(!me->is_fighting())
//        return notify_fail("七星法中的［击星诀］只可以在战斗中施展！\n"); 
        
        if( !target ) target = me;
                else if(me!=target)
                return notify_fail("七星法中的［击星诀］只可以用在自己的身上。\n");
    
        if((int)me->query_skill("spells") < 80 )
                return notify_fail("你的法术不够高！\n"); 
        if( !target
                ||!target->is_character()
                ||target->is_corpse() )
                return notify_fail("你要对谁施展这个法术？\n");
    
        if(target->query_temp("in_jixing"))
                return notify_fail("你现在并不需要施展击星诀。\n");
    
        if((int)me->query("mana") < 150 )
                return notify_fail("你的法力不够！\n");
    
        me->add("mana", -150);  
        msg = HIC "$N口中念念有词，一道光芒从$N头顶射出，缭绕在$N周围！\n\n" ; 
/*  ap = me->query_skill("spells");
    ap = ( ap * ap /100 * ap/30 ) * (int)me->query("sen") ;
    dp = offensive_target(me)->query("combat_exp");
    if( random(ap+me->query("combat_exp")) + me->query("combat_exp") > dp )
    {*/
        msg +="光芒化成一股力量，注入了$N的全身！\n";
        lvl = (int)me->query_skill("spells")/2;
        if ((string)me->query("class") != "wudang") lvl=lvl /2;
        target->set_temp("in_jixing",1);
        target->add_temp("apply/damage",lvl);
        seteuid(ROOT_UID);
        target->start_call_out( (: call_other, __FILE__, "remove_hanxing",target, lvl :),
                                random(lvl)+lvl);
/*    } else
        msg += "但是马上就消失了。\n";*/
    
        message_vision(msg+NOR,me);
        me->start_busy(1);
        return 1;
} 
void remove_hanxing(object me, int lvl)
{
    me->delete_temp("in_jixing");
    me->add_temp("apply/damage",-lvl);
    message_vision(HIY "\n\n$N浑身一闪，似乎有股光芒射出体外。\n\n" NOR, me);
}  
