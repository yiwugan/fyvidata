 // mindheal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( !target )
                return notify_fail("你要用真气为谁疗伤？\n"); 
        if( me->is_fighting() || target->is_fighting())
        return notify_fail("战斗中无法运用『丹心照』疗伤！\n"); 
        if( (int)me->query("force")< 600 )
                return notify_fail("你的真气不够。\n");
        
        if (target!=me)
                message_vision(
        HIY "$N神情凝重，手掌紧贴$n额头，缓缓将真气渡入$n体内....\n"
        "片刻之后，$n神色一缓，胸口暖意顿生，有如旭日当空，长吁一口浊气，心神安宁多了。\n" NOR,
        me, target );
        else 
                message_vision(
        HIY "$N神情凝重，一手抚额，真气流转，....\n"
        "片刻之后，$N神色一缓，胸口暖意顿生，有如旭日当空，长吁一口浊气，心神安宁多了。\n" NOR,
        me); 
        target->receive_curing("sen", 5 + (int)me->query_skill("force"));
        me->add("force", -150);
        me->set("force_factor", 0); 
        return 1;
}  
