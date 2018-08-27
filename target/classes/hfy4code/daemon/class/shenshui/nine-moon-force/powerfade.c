 // powerfade.c
#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
        int skill, num;
        if( target != me ) 
                return notify_fail("你只能用九阴心经压制自己的杀气。\n");
        if( (int)me->query("force") < 100 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("bellicosity") <= 0 )
                return notify_fail("你现在毫无杀气。\n");
        
        skill = me->query_skill("nine-moon-force",1);
        num = 40 + skill;
        
        me->add("bellicosity", -num );
        me->add("force", -100); 
        message_vision(HIC "$N双眼微合，施展九阴心经，放慢呼吸，开始收敛自己的阴气。。。\n" NOR, me);
        
        me->start_busy(1);   
        return 1;
} 
 
