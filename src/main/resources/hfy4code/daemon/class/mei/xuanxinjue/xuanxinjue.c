 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 40 )
                return notify_fail("你的真气不够。\n"); 
		write( HIW "你运起『玄心决』，开始运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + 
HIW"运起『玄心决』，掌心相抵，掌间透出隐隐白气，笼罩着" + me->name()+ HIW"全身。\n" NOR, environment(me), me); 
        me->receive_curing("kee", 20 + (int)me->query_skill("xuanxinjue",1)*2);
        me->add("force", -40);
        me->set("force_factor", 0); 
        return 1;
}
      
