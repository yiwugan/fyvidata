// libie.c ���
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        mapping exits;
        string *dirs;
        duration--;
        if( duration < 0 )      return 0; 
        me->receive_wound("sen", 60);
        if(mapp(exits = environment(me)->query("exits"))) { 
                tell_object(me, WHT"�����к�Ȼӿ��Ī���˸У�ֻ������������ãȻ��֪������\n"NOR); 
                message("vision", me->name() + "������࣬ʧ��һ������Ŀ�ĵ����ߡ�\n", 
                        environment(me), me); 
                dirs = keys(exits);
                me->ccommand("go " + dirs[random(sizeof(dirs))]);
        }
        me->apply_condition("libie", duration);
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
