#include <ansi.h> 
int exert(object me, object target)
{
        int skill, extra;
        int tarforce;
        int myforce;      
        skill=me->query_skill("force",1);
    
        if (me->query("class")!="yihua")
                return notify_fail("只有移花宫弟子才能使用『明玉神功』。\n");             
        
        if (skill<130)  return notify_fail("你的明玉神功还不够高深。\n");
        if( (int)me->query("max_force")< 2000 )
                return notify_fail("你的内力不够深厚，使用此招容易走火入魔。\n"); 
        if( me->is_fighting())
        	return notify_fail(HIR "战斗中不能使用明玉神功吸取内力！\n"NOR);
        if( me->query("force")>=6*(int)me->query("max_force") )
                return notify_fail("你只能吸取这么多内力了。\n");           
        if( !target )
        	return notify_fail("你想要吸取谁的内力？\n");
        if(!living(target))
        	return notify_fail("不是活物，哪来的内力？\n");	
        if( target == me)
                return notify_fail("『明玉神功』不能用在自己身上。\n");
        if (target->query("force")<=0)
                return notify_fail("此人没有内力的，不值得你用此神功。\n");                       
        message_vision(
                HIM "$N深吸一口真气，双掌猛地对准$n的膻中大穴按了下去！！\n\n"NOR,
                me, target ); 
        tarforce=target->query("force");
        myforce=me->query("force");
	tell_object(target, HIR "你顿觉全身内力如水银般循孔飞泄而出！\n" NOR);
	tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);
	target->set("force",0);
	me->add("force",tarforce);
	target->start_busy(1);
	message_vision(
			WHT"$N觉得全身好像虚脱了一般，瘫软在地……\n"NOR,
			target);
	target->unconcious();
	me->start_busy(1);
        return 1;
}  
