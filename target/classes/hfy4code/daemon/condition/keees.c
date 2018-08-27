 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
	      int jing;
	       jing = (me->query("con")/2);
	       
        if (me->query_temp("qifang") < 1) 
        	{
        		me->set_temp("resistance/kee",jing);
        		me->set_temp("qifang",1);
        	}
        
        me->apply_condition("keees", duration - 1);
        
        if( duration < 1 )
        	{
        tell_object(me, HIW "�����ϻ�Ѫ����ҩЧ�����ˣ�\n" NOR );
         	me->delete_condition("keees");	
        	me->delete_temp("qifang");	
        	me->add_temp("resistance/kee",- jing);
        	return 0;
          }
        return 1;
}       
