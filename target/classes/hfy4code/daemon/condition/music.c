 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration){
        if(environment(me)->query("indoors") == "huashan"
         ||     environment(me)->query("outdoors") == "huashan") 
         {              
                message("vision", "���ĵ�����ʱ��ʱ������ʱ��ҹ�������ʱ���ˮ���ܣ���ʱ��ɽ��Ʈ������\n" NOR,environment(me));
                me->apply_condition("music", duration - 1);
                if( duration < 1 ) return 0;    
         } else {
                        me->clear_condition("music");
                }
                return 1; 
}    
