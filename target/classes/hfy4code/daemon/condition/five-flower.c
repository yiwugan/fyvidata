 // bat_poison.c
#include <ansi.h> 
int update_condition(object me, int duration)
{
        me->receive_wound("kee", 40);
        me->receive_damage("sen", 40);
        me->apply_condition("bat_poison", duration - 1);
        if( duration < 1 )
                tell_object(me, HIG "你中的五花毒终于发作光了！\n" NOR );
        else
                tell_object(me, RED "你中的五花毒发作了，满眼看到的都是色彩斑斓的花朵在飞旋！\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}      
