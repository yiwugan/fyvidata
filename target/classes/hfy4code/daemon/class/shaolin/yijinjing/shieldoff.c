 //mimicat@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra,ratio,delay;
        
        extra=me->query_skill("yijinjing",1);
        if(extra<150)
                return notify_fail("你易筋经的等级不够高。\n");
                
        if(!me->query_temp("shield_force"))
                return notify_fail("你不在运功中。\n");
        if (me->is_fighting())
        {
                return notify_fail("在战斗中不可收回护体神功。\n");
        }
        /*
        if(me->query("class")!="shaolin")
                return notify_fail("只有少林高僧才能使用易筋经的护体神功。\n");*/
        
        if(target&& me!=target)
                return notify_fail("取消护体神功只能用在自己身上。\n");
        call_other(__DIR__"shield.c","stop_effect",me);
        me->start_busy(3);
        me->set("force",0);
        me->delete_temp("shield_force");
    me->delete_temp("till_death/shield_lock");
    message_vision(HIW"$N长吐了一口气,慢慢收回了身边的护体气墙。\n"NOR,me);
        return 1;
}    
