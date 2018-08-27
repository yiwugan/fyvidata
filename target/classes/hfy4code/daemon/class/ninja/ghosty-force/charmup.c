#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;
        
        if( (int)me->query_temp("charmup") ) 
                return notify_fail("你已经魅力四射，光彩照人了。\n");
        
        if( target != me ) return 
                notify_fail("你只能用无坎真阴提升自己的魅力。\n");
        
        if( (string)me->query("gender") != "女性" )
                return notify_fail("无坎真阴是只有女子才能练的内功。\n");
        
        skill= me->query_skill("ghosty-force",1);
        if (skill<100)
                return notify_fail("你的无坎真阴还不够熟练\n");
        if( (int)me->query("force") < 200 )     
                return  notify_fail("你的内力不够。\n");
        
        if( (int)me->query_temp("charmup") ) 
                return notify_fail("你已经魅力四射，光彩照人了。\n");
        
        me->add("force", -200);
        
        skill=skill/15;
        me->add_temp("apply/personality",skill);
        me->set_temp("charmup",1);
        
        message_vision(HIM "$N的眼光变得迷离，散发出一股令人无法抗拒的魅力．．．\n" NOR, me);
            
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,skill:), skill*4);
        if(me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void remove_effect(object me,int extra)
{
        me->add_temp("apply/personality", -extra);
        me->delete_temp("charmup");
        message_vision(HIW"$N的眼神恢复正常，看来已经回到了清醒状态。\n"NOR,me);
        
} 
