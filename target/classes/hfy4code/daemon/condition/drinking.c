 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration){
               
               if (duration ==100 || duration == 300 || duration ==500 || duration ==800 ||duration ==1000)
                  {message("vision", "��о����̲��������ڳ�θ��ɢ����ů�⣬�ƺ����ò����ٽ�ʳ��\n" NOR,environment(me));}
                  
                me->apply_condition("drinking", duration - 1);
                 me->set("water",this_player()->max_water_capacity());

              if( duration < 1 )
                {
                        me->clear_condition("drinking");
                }
                return 1; 
}    
