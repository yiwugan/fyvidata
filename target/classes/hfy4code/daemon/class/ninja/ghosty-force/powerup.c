#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,amt;
        if( target != me ) return
        notify_fail("你只能用无坎真阴提升自己的防御力。\n");
        /*if( (string)me->query("gender") != "女性" )
                return notify_fail("无坎真阴是只有女子才能练的内功。\n");
        */
        if( (int)me->query("force") < 100 )     return
                        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) return
                        notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("force")/2;
        if (skill>=180) skill=180;
        me->add("force", -100);
        message_vision( HIR"$N默运无坎真阴神功，全身象一团棉絮般轻飘起来！\n" NOR, me);
        amt=skill/2;
        me->add_temp("apply/dodge", amt);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,
amt :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的无坎真阴运行完毕，全身没了那种轻飘飘的感觉。\n");
}        
