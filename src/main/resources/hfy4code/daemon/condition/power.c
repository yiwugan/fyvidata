 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
	      int pow;
	       pow = (me->query("str")*4/3);
        if (me->query_temp("pstr") < 1) 
        	{
        		me->add_temp("apply/strength", pow);
        		me->set_temp("pstr",1);
        	}
        
        me->apply_condition("power", duration - 1);
        
        if( duration < 1 )
        	{
        tell_object(me, HIW "你身上大力金刚丸的药效消退了！\n" NOR );
         	me->delete_condition("power");	
        	me->delete_temp("pstr");	
        	me->set_temp("apply/strength", 0);
        	return 0;
          }
        return 1;
}       
