 // �������
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        me->receive_damage("gin", 80);
        me->receive_damage("kee", 100);
        me->apply_condition("wumuqibing", duration - 1);
        if( duration < 1 )
                message_vision(HIG "$N"+HIG"���ڳ�������Ҿ����󷨣�\n"NOR, me );
        else
                message_vision(HIW "��������$N"+HIW"��ǰǰ��������ս���޶���������裬$N"+HIW"���ɵ��ķ����ң�\n" NOR, me );
        if( duration < 1 ) 
                return 0;
        return 1;
}    
