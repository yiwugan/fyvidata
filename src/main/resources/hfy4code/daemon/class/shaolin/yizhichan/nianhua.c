 //mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int extra);
int perform(object me, object target)
{
        string msg;
        int extra;
        
        if(me->query("class")!="shaolin")
                return notify_fail("拈花是少林绝技，你怎么可能会使呢？\n");
        extra = me->query_skill("yizhichan",1);
        if(extra<150) return notify_fail("你一指禅的修为不够，无法使出“拈花”的绝招。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("“拈花”只能对战斗中的对手使用。\n");
        if (me->query_temp("nianhua_beauty")+1>time())
                return notify_fail("你心神不静，尚不能使用“拈花”\n");        
        if(target->query_skill_mapped("dodge") == "anxiang-steps" && random(6)>1) {
                tell_object(me,HIM"\n你看着对手风中飘舞的身影，只感到生命的多彩，这一指竟发不出去。\n"NOR);
                me->set_temp("nianhua_beauty",time());
                return 1;
                }       
        message_vision(HIG"\n$N右手食中两指轻轻搭住，作拈花之状，左手同时缓缓伸起，向着$n弹了过去。\n\n"NOR,me,target);
        begin_perform(me,target,3,extra);
        me->set_temp("nianhua_beauty",time());
        return 1;
        
}      
string *perform_msg=({
        YEL"千丝万缕的指风无声无息地袭向$n。\n\n"NOR,
        YEL"天界仿佛响起了梵唱，指劲引动气流发出低低的声音。\n\n"NOR,
        YEL"缓缓的指劲似清风拂上凝露的花瓣，然而露珠滚落时，花瓣也随风飘散了。。。。。。\n\n"NOR
        }); 
int begin_perform(object me,object target,int count,int extra)
{
        string msg;
   int enf,ext,enp;
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return 0;
        if(count)
        {
                msg=perform_msg[--count];       
                enf=me->query_skill("force");
                ext=extra*extra*extra+me->query("combat_exp");
                enp=target->query("combat_exp");
                message_vision(msg,me,target);
                if(random(ext+enp)>enp)
                {
                        message_vision(HIR"$n被一股柔和的指力一击，只觉心头别样地一跳！\n"NOR,me,target);
                        target->receive_damage("kee",enf*2+random(enf*extra)/50);
                        COMBAT_D->report_status(target);
                }
                else
                        message_vision(HIC"$n看破指风来势，以巧妙身法闪开了这一击！ \n\n"NOR,me,target);
                if (me->query_busy()<3) me->start_busy(3);
                if(random(2)) begin_perform(me,target,count,extra);
                else
                        call_out("begin_perform",1,me,target,count,extra);
                return 1;
        }
         
        return 1;
}  
