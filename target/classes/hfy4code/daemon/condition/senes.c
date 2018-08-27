 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
	      int jing;
	       jing = (me->query("dur")/2);
	       
        if (me->query_temp("shenfang") < 1) 
        	{
        		me->set_temp("resistance/sen",jing);
        		me->set_temp("shenfang",1);
        	}
        
        me->apply_condition("senes", duration - 1);
        
        if( duration < 1 )
        	{
        tell_object(me, HIW "你身上凝神丹的药效消退了！\n" NOR );
         	me->delete_condition("senes");	
        	me->delete_temp("shenfang");	
        	me->add_temp("resistance/sen",- jing);
        	return 0;
          }
        return 1;
}       
