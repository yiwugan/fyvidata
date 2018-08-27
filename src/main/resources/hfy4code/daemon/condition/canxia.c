 // snake_poison.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration){
        int i,dam_kee,dam_gin,dam_sen;
        
        i = 30/(duration+1);
    dam_kee = (int) me->query("max_kee")/i;
    dam_gin = (int) me->query("max_gin")/i;
    dam_sen = (int) me->query("max_sen")/i;
    me->receive_wound("kee", dam_kee);
    me->receive_wound("gin", dam_gin);
    me->receive_wound("sen", dam_sen);
        me->apply_condition("canxia", duration - 1);
        if( duration < 1 ) {
            tell_object(me, MAG"������ϼ"NOR + "�������ˡ�\n");
                } else {
                        tell_object(me, MAG"������ϼ"NOR + "�����ˣ����������һ���䣬Ƥ��͸��һ����ɫ��\n");
                        message("vision", me->name() + "�ƺ������䣬����Ӳ����ͣ�ش���£�Ƥ����͸��һ��������ɫ��\n", 
                                        environment(me), me);
                }
        if( duration < 1 ) 
                return 0;
        return 1;
} 
int condition_type(){
        return NERVE_POISON;
}     
