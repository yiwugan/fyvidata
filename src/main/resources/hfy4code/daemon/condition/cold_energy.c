 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        int effect = 0;
        if(me->query("force") >= 1200)
        {
        me->receive_heal("kee", 300);
        me->receive_heal("gin", 300);
        me->receive_heal("sen", 300);
        me->receive_curing("kee", 300);
        me->receive_curing("gin", 300);
        me->receive_curing("sen", 300);
        effect = 1;
        }
        else
        {
        me->receive_damage("kee", 400);
        me->receive_damage("gin", 400);
        me->receive_damage("sen", 400);
        me->receive_wound("kee", 400);
        me->receive_wound("gin", 400);
        me->receive_wound("sen", 400);
        effect = -1; 
        }
        me->apply_condition("cold_energy", duration - 1);
        if(effect > 0 )
        {
        if( duration < 1 )
        tell_object(me, HIC "天山雪莲的功效散光了！\n" NOR );
        else
        tell_object(me, HIC "你用内力带动天山雪莲的寒气在体内运行一周！\n" NOR );
        if( duration < 1 ) 
                return 0;
        }
        else
        {
        if( duration < 1 )
        tell_object(me, HIC "天山雪莲的寒气终于散光了！\n" NOR );
        else
        tell_object(me, HIC "天山雪莲的寒气发作了！你浑身发冷，不停地打颤！\n" NOR );
        if( duration < 1 ) 
                return 0;
        }
        return 1;
}  
