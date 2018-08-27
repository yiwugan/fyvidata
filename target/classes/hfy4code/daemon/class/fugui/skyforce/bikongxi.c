 // lifeheal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( !target )
                return notify_fail("你要用真气为谁疗伤？\n"); 
        if( me->is_fighting() || target->is_fighting())
        return notify_fail("战斗中无法运用『碧空洗』疗伤！\n"); 
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够。\n"); 
        if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
                return notify_fail( target->name() + "已经受伤过重，经受不起你的真气震荡！\n");
        if (target!=me)
                message_vision(
        HIW "$N体内真气流转，双掌紧贴$n背心，缓缓地用内力助$n疗伤....\n"
        "片刻之后，$N头顶冒出丝丝白气，$n深呼一口气，心头有如碧空一洗，脸色看起来红润多了。\n" NOR,
                me, target );
        else 
                message_vision(
        HIW "$N体内真气流转，..\n"
        "片刻之后，$N头顶冒出丝丝白气，深呼一口气，心头有如碧空一洗，脸色看起来红润多了。\n" NOR,
                me); 
        target->receive_curing("kee", 10 + (int)me->query_skill("force"));
        me->add("force", -150);
        me->set("force_factor", 0); 
        return 1;
} 
