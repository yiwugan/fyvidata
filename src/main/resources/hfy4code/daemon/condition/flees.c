 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
	      int jing;
	       jing = (me->query("fle")/2);
	       
        if (me->query_temp("jingfang") < 1) 
        	{
        		me->set_temp("resistance/gin",jing);
        		me->set_temp("jingfang",1);
        	}
        
        me->apply_condition("flees", duration - 1);
        
        if( duration < 1 )
        	{
        tell_object(me, HIW "你身上固精丹的药效消退了！\n" NOR );
         	me->delete_condition("flees");	
        	me->delete_temp("jingfang");	
        	me->add_temp("resistance/gin",- jing);
        	return 0;
          }
        return 1;
}       
