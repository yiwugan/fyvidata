 // powerfade.c
#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
        int extra; 
        if( target != me ) 
                return notify_fail("你只能对自己使用『与世无争』。\n");
        if( me->is_fighting() )
                return notify_fail("战斗中不能运用『与世无争』！\n"); 

        extra = me->query_skill("wuzheng-force",1);
        if(extra < 100 )
                return notify_fail("你的无争心法火候不够。\n"); 
        if( (int)me->query("force") < 300 )     
                return notify_fail("你的内力不够。\n");
		if(me->query("class") != "bat") extra = extra / 10;

        if( (int)me->query("bellicosity") > 0 )
		{
				me->add("bellicosity", -extra-100 );
		}

		message_vision(WHT"$N催动内功，只感觉浑身戾气慢慢消散，说不出的舒服……\n" NOR, me); 

        me->receive_curing("kee", 6*extra);
        me->receive_curing("sen", 6*extra);
        me->receive_curing("gin", 6*extra);
        me->add("force", -300);
        me->set("force_factor", 0); 
        me->start_busy(2);
        return 1;
}       
