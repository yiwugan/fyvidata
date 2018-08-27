 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
	      int lx;
	       lx = (me->query("spi")/5*3);
	       
        if (me->query_temp("lingxing") < 1) 
        	{
        		me->add_temp("apply/spirituality", lx);
        		me->set_temp("lingxing",1);
        	}
        
        me->apply_condition("spiri", duration - 1);
        
        if( duration < 1 )
        	{
        tell_object(me, HIW "你身上明堂灵犀丸的药效消退了！\n" NOR );
         	me->delete_condition("spiri");	
        	me->delete_temp("lingxing");	
        	me->add_temp("apply/spirituality", - lx);
        	return 0;
          }
        return 1;
}       
