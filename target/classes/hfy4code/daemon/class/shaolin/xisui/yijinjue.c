 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount); 
int perform(object me, object target)
{
        string msg;
        int amount;
        
        if( !target ) target = me; 
        if((int)me->query_skill("xisui",1) < 120 )
                return notify_fail("你的洗髓经不够高！\n");
        if( !target || target != me)
                return notify_fail("易筋诀只能用在自己身上。\n");
        if( (int)target->query_temp("xisui") ) 
                return notify_fail("你已经在施展易筋诀了。\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不够！\n");
        
        me->receive_wound("kee", 100);
        msg = HIC "$N凝神聚力，骨骼咯咯作响，身形居然高大了一截！！\n\n" NOR;
        message_vision(msg,me);
        
        amount = me->query_str()/10;
        
        me->add_temp("apply/strength", amount);
        me->set_temp("xisui",1);
        me->start_busy(2);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,amount:), me->query_skill("xisui",1)); 
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->delete_temp("xisui");
        tell_object(me, "你运功完毕，恢复正常。\n");
        me->add_temp("apply/strength",-amount);
}  
