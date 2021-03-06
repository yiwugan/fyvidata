 // tunyue.c
#include <ansi.h> 
int exert(object me, object target)
{
        int skill, extra;
        
        skill=me->query_skill("wolf-force",1);
        extra= me->query_skill("summonwolf",1);
    
        if (me->query("class")!="wolfmount")
                return notify_fail("只有狼山弟子才能使用『天狼吞月』。\n");             
        
        if (extra<130)  return notify_fail("你的唤狼之术不够高深。\n");
        if (skill<130)  return notify_fail("你的天狼心法不够高深。\n"); 
        if(me->query_temp("wolfbuff/tunyue")+240>time())
                return notify_fail("『天狼吞月』不能连续施展！！\n");
        if( (int)me->query("force")< 100 )
                return notify_fail("你的真气不够。\n"); 
        if( me->is_fighting())  return notify_fail(HIR "战斗中不能使用『天狼吞月』！\n"NOR);
        if( !target )   return notify_fail("你的『天狼吞月』要用在哪一头狼身上？\n");
        if( target->query("id") != "wolf" )
                return notify_fail(target->query("name")+"不是狼，不能使用『天狼吞月』。\n");
        if( target->query("no_wolf_force") )
        	return notify_fail("不能在幽灵狼身上使用『天狼吞月』。\n");
        if( me != target->query("possessed"))
                return notify_fail("『天狼吞月』只能用在你自己召唤的狼身上。\n");
        if (target->query("wolfbuff"))
                return notify_fail("你已经在这头狼身上下过天狼心法了。\n");
        
        if( target->query_temp("is_unconcious")) target->revive();
        
        message_vision(
                HIB "$N深吸一口气将手掌搭在$n"HIB"背心，刹时间，似乎心意与$n"HIB"相通....\n\n$n" 
                HIG"双眼闪动莹莹的绿光，抖了抖身体，发出一声深沉有力的长嚎！\n" NOR,
                me, target ); 
        target->start_call_out( (: call_other, __FILE__, "remove_tunyue",target :),
                                skill);                          
        target->set("max_kee",me->query("max_kee")*extra/20);
        target->set("eff_kee",target->query("max_kee"));
        target->set("kee",target->query("max_kee"));
        target->set("str",1);
        target->set("wolfbuff",1);
   me->set_temp("wolfbuff/tunyue",time());
        me->add("force",-100);
        me->start_busy(2);
        return 1;
} 
void remove_tunyue(object wolf)
{
    wolf->delete("wolfbuff");
    message_vision(HIG "\n\n$N"HIG"周身颤抖了几下，化作一团绿炎消失了。\n", wolf);
    wolf->die();
}   
