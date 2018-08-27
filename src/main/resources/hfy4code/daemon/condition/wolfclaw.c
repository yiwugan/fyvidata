//wolf-claw
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration){
        int i,dam_kee,dam_gin,dam_sen;
        
//        i = 30/(duration+1);
    dam_kee = (int) me->query("max_kee")/20;
//    dam_gin = (int) me->query("max_gin")/20;
    dam_sen = (int) me->query("max_sen")/20;
    me->receive_wound("kee", dam_kee);
//    me->receive_wound("gin", dam_gin);
    me->receive_wound("sen", dam_sen);
        me->apply_condition("wolfclaw", duration - 1);
        if( duration < 1 ) {
            tell_object(me, HIW"被狼王抓伤的地方慢慢的愈合了。\n"NOR);
                } else tell_object(me, WHT"你的手臂被狼王抓伤了，伤口流血不止。\n");
        if( duration < 1 ) 
                return 0;
        return 1;
} 
int condition_type(){
        return WOLF_POISON;
}     
