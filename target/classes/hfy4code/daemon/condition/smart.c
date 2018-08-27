 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
	      int sma;
	       sma = (me->query("int")/10);
	       
        if (me->query_temp("smarttt") < 1) 
        	{
        		me->add_temp("apply/intelligence", sma);
        		me->set_temp("smarttt",1);
        	}
        
        me->apply_condition("smart", duration - 1);
        
        if( duration < 1 )
        	{
        tell_object(me, HIW "你身上大智大慧丹的药效消退了！\n" NOR );
         	me->delete_condition("smart");	
        	me->delete_temp("smarttt");	
        	me->set_temp("apply/intelligence", 0);
        	return 0;
          }
        return 1;
}       
