 // bat_poison.c
#include <ansi.h> 
int update_condition(object me, int duration)
{
        me->receive_wound("kee", 40);
        me->receive_damage("sen", 40);
        me->apply_condition("bat_poison", duration - 1);
        if( duration < 1 )
                tell_object(me, HIG "���е��廨�����ڷ������ˣ�\n" NOR );
        else
                tell_object(me, RED "���е��廨�������ˣ����ۿ����Ķ���ɫ�ʰ�쵵Ļ����ڷ�����\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}      
