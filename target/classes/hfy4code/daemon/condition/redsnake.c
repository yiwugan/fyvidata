 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        me->receive_wound("kee", 60);
        me->receive_wound("gin", 60);
        me->receive_wound("sen", 60);
        me->apply_condition("redsnake", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "���е�" HIG "������" HIW "���ڷ������ˣ�\n" NOR );
        else
        tell_object(me, HIW "���е�" HIG "������" HIW "�����ˣ�\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}   
