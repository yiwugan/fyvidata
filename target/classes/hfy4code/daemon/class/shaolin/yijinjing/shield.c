 //mimicat@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra,ratio,delay;
        
        if(me->query("class")!="shaolin")
                return notify_fail("只有少林高僧才能使用易筋经的护体神功。\n");
        extra=me->query_skill("yijinjing",1);
        if(extra<100)
                return notify_fail("你易筋经的等级不够高。\n");
        if(target&& me!=target)
                return notify_fail("护体神功只能用在自己身上。\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("你的内力不够。\n");
        if(me->query_temp("ninjitsu_berserk")) 
                return notify_fail("忍术和易筋经不相容。\n");
        if(me->query_temp("shield_force"))
                return notify_fail("你已经在运功中了！！\n");
        delay = 3-extra/100;
                ratio = extra *5;
                if (me->query("once_xman")==1) ratio = ratio *2;
        me->start_busy(3);
        me->add("force", -500);
        message_vision(YEL"$N深吸一口真气，内力澎湃而出。。。。。\n"NOR,me);
        me->start_call_out( (: call_other, __FILE__, "take_effect", me, ratio :), delay);
        extra=extra+random(extra);
        //me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra);
        call_out("remove_effect",extra,me);
        return 1;
} 
void take_effect (object me, int ratio) 
{
        message_vision(YEL"气流扰动，似乎在$N周围结成一围气墙。\n"NOR,me);
        me->set_temp("till_death/shield_lock",1);
        me->set_temp("shield_force/type","force");
        me->set_temp("shield_force/ratio",ratio);
        me->set_temp("shield_force/msg",
                YEL"$N招式甫及$n身前三尺之外，便似遇上了一层柔软之极，却又坚硬之极的屏障。\n"NOR);
}          
void remove_effect(object me)
{
        me->delete_temp("shield_force");
        me->delete_temp("till_death/shield_lock");
        message_vision(HIW"$N身上的气墙渐渐消失了。\n"NOR,me);
} 
void stop_effect(object me)
{
        remove_call_out("remove_effect");
} 
