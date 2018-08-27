 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( target != me ) 
                return notify_fail("你只能用内功疗自己的伤。\n"); 
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 100 )
                return notify_fail("你的真气不够。\n"); 
        write( HIW "你默念苍生诀，抱中守一，开始运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + "气随意转，一周天后吐出一口浊气站起身来，脸色看起来好多了。\n" NOR,
                environment(me), me); 
        me->receive_curing("kee", 20 + (int)me->query_skill("longlife-force",1)*2 );
        me->add("force", -100);
        me->set("force_factor", 0); 
        return 1;
}      
