 //silencer@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra,ratio,delay,bonus;
        
        if (me->query("class")!="taoist")
                return notify_fail("只有三清宫的弟子才能用天罡真气。\n");
        
        //if  (me->query("family/master_name")=="丁白云") bonus = 1;
        //      else bonus=3;
        // <= no reason
        bonus=3;        
        extra=me->query_skill("gouyee",1);
        if(extra<50)
                return notify_fail("你谷衣心法的等级不够高。\n");
        if(target&& me!=target)
                return notify_fail("天罡真气只能用在自己身上。\n");
        if( (int)me->query("force") < 300 )
                return notify_fail("你的内力不够。\n");
        if(me->query_temp("shield_force"))
                return notify_fail("你已经在运功中了！！\n");
        
        delay = 4-extra/50;
        ratio = extra * bonus;
        me->start_busy(3);
        me->add("force", -300);
        message_vision(MAG"$N暗运法力，脸色忽青忽紫。。。。。\n"NOR,me);
        me->start_call_out( (: call_other, __FILE__, "take_effect", me, ratio :), delay);
        extra=extra+random(extra);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra);
        return 1;
} 
void take_effect (object me, int ratio) 
{
        message_vision(MAG"紫气越来越浓，笼罩在$N周围。\n"NOR,me);
        me->set_temp("till_death/shield_lock",1);
        me->set_temp("shield_force/type","mana");
        me->set_temp("shield_force/ratio",ratio);
        me->set_temp("shield_force/msg",
           MAG"$N招式甫及$n身前三尺之外，便如牛入海,消失在紫气中。\n"NOR);
}          
void remove_effect(object me)
{
        me->delete_temp("shield_force");
        me->delete_temp("till_death/shield_lock");
        message_vision(HIW"$N身上的紫气渐渐消失了。\n"NOR,me);
}  
