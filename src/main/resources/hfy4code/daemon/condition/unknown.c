 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
        me->receive_wound("kee", 20);
        me->receive_wound("gin", 20);
        me->receive_wound("sen", 20);
        me->apply_condition("unknown", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "�����ϲ�֪�е�ʲô�����ڷ������ˣ�\n" NOR );
        else
        tell_object(me, HIW "�����ϵĶ��ط����ˣ�\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}       
