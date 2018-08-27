 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        me->receive_wound("kee", 500);
        me->receive_damage("sen", 100);
        me->apply_condition("snakees", duration - 1);
        if( duration < 1 )
                tell_object(me, HIW "你中的蛇毒终于发作光了！\n" NOR );
        else
                tell_object(me, HIR "你中的蛇王蛇毒发作了！\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}       
