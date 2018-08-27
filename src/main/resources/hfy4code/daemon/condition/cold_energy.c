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
        tell_object(me, HIC "��ɽѩ���Ĺ�Чɢ���ˣ�\n" NOR );
        else
        tell_object(me, HIC "��������������ɽѩ���ĺ�������������һ�ܣ�\n" NOR );
        if( duration < 1 ) 
                return 0;
        }
        else
        {
        if( duration < 1 )
        tell_object(me, HIC "��ɽѩ���ĺ�������ɢ���ˣ�\n" NOR );
        else
        tell_object(me, HIC "��ɽѩ���ĺ��������ˣ�������䣬��ͣ�ش����\n" NOR );
        if( duration < 1 ) 
                return 0;
        }
        return 1;
}  
