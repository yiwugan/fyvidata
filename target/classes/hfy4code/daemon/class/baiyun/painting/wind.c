#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target)
{
        int extra;
        if (me->query("class") != "baiyun") 
                return notify_fail("只有白云岛弟子可以使用「云开雾散」。\n");
        extra = me->query_skill("painting", 1);
        if(extra < 50) 
                return notify_fail("你的画道心法不够纯熟，无法使用［云开雾散］。\n");
        if (me->is_naked())
                return notify_fail("你已经赤条条的了，再来个［云开雾散］，恐怕不太好吧。\n");
        
        /*if( !me->is_fighting() )
                return notify_fail("［云开雾散］只能在战斗中使用。\n");
          */
        if( !target ) target = offensive_target(me);
        
        if( (int)me->query("force") < 200 )
                return notify_fail("你的内力不够。\n"); 
        
        if( me->is_fighting() || !me->query_temp("apply/painting") ) message_vision(HIG"$N运起画道心法，衣带飘飘，似当风而动，你只觉周围空气霎时如云开雾散般清新舒畅。\n"NOR,me);
        else  return notify_fail("你现在无须使用［云开雾散］。\n");
        me->add("force", -50);
        me->delete_temp("till_death/lockup");
        if (!me->query_temp("apply/painting"))
                me->set_temp("apply/painting", extra);
        call_out("remove_painting",5 + extra/10, me);
        me->start_busy(1);
        return 1;
}  
void remove_painting(object me)
{
    me->delete_temp("apply/painting");
    tell_object(me, "你的内力忽有滞涩，［云开雾散］的功效消失了。\n");
}
 
