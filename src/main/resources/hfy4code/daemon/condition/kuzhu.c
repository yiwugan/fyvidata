 // TIE@FY3
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
        me->receive_heal("sen", 15);
        message_vision("$N������һ�ݣ������ƺ��ֺ���һЩ��\n",me);
        me->apply_condition("kuzhu", duration - 1);
        if( duration < 1 ) 
                return 0;
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
        return NO_CURE;
}    
