 // drunk.c
inherit F_CLEAN_UP;  
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        int limit; 
        limit = (me->query("con") + (int)me->query("max_force") / 50) * 2; 
        if( duration > limit
        &&      living(me) ) {
                me->unconcious();
                return 0;
        } else if( duration > limit/2 ) {
                tell_object(me, "��������ֿ����̣�����ܲ����ˣ�\n");
                message("vision", me->name() + "�촽���ף��ƺ�������ˮ�ˣ�\n",
                        environment(me), me);
        } 
        me->apply_condition("salt_drug", duration - 1);
        if( !duration ) return 0;
        return 1;
} 
