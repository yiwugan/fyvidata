 // qicaibat.c  �߲�����
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        me->receive_wound("kee", 5000);
        me->receive_damage("sen", 500);
        me->receive_damage("gin", 500);
        me->apply_condition("qicaibat", duration - 1);
        if( duration < 1 )
                tell_object(me, HIG "���е��߲��������ڷ������ˣ�\n" NOR );
        else
                tell_object(me, RED "���е��߲����𶾷����ˣ�\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}    
