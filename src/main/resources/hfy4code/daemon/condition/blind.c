 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        if(!me->query_temp("block_msg/all"))
        {
                tell_object(me, HIW"��ֻ������ǰ��ãã��һƬ��ʲô���������ˡ�\n" NOR );
                me->set_temp("block_msg/all",1);
        }
        me->apply_condition("blind", duration - 1);     
        if (duration<1)
        {
                me->delete_temp("block_msg/all");
                tell_object(me, HIG"���������ģ�����۾���ʼ���Էֱ���Χ�������ˡ�\n" NOR);
                return 0;
        }
        return 1;
} 
int condition_type()
{
// in condition.h
/* 
#define NO_CURE                 10
#define NON_POISON              9
#define BLOOD_POISON            8
#define NERVE_POISON            7
#define BRAIN_POISON            6
#define OBSCENE_POISON          5
#define GENERIC                 0 
*/ 
        return BRAIN_POISON;
}     
