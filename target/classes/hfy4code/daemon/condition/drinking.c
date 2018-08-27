 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration){
               
               if (duration ==100 || duration == 300 || duration ==500 || duration ==800 ||duration ==1000)
                  {message("vision", "你感觉到滋补鱼翅羹仍在肠胃内散发的暖意，似乎良久不用再进食。\n" NOR,environment(me));}
                  
                me->apply_condition("drinking", duration - 1);
                 me->set("water",this_player()->max_water_capacity());

              if( duration < 1 )
                {
                        me->clear_condition("drinking");
                }
                return 1; 
}    
