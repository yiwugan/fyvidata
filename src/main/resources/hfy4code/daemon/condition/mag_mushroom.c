 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
    me->receive_wound("kee", 20);
    me->receive_wound("gin", 20);
    me->receive_wound("sen", 20);
    me->apply_condition("mag_mushroom", duration - 1);
        if( duration < 1 )
    tell_object(me, YEL "���³�һ�����������ڸо���̹����࣡\n" NOR );
        else
    tell_object(me, HIM "��θ��һ���ʹ�������������ᣬð������ĺ���ɫ���飡\n" NOR );
    message("vision", me->name() + "���ְ�סθ���������������ᣬͷ��ð������ĺ���ɫ���Σ�\n", 
                        environment(me), me);
        if( duration < 1 ) 
                return 0;
        return 1;
}   
