 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        me->receive_wound("kee", 10);
    me->receive_wound("gin", 10);
    me->receive_wound("sen", 10);
        me->apply_condition("mushroom", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "�����ڸо����õĶ��ˣ�\n" NOR );
        else
        tell_object(me, HIW "��θ��һ���ʹ��ͷ��ð������ĺ��飡\n" NOR ); 
        message("vision", me->name() + "���ְ�סθ������ɫ�Ұף�ͷ��ð������ĺ��Σ�\n",  
                        environment(me), me);
        if( duration < 1 ) 
                return 0;
        return 1;
}     
