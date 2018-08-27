#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount); 
int exert(object me, object target, int amount)
{
        int skill;
        skill = me->query_skill("jingxing",1); 
//      if (me->query("class")!="assassin")
//              return notify_fail ("静心诀只有金钱帮弟子能使用。\n"); 
        if(skill < 50) 
                return notify_fail("你的静行心法太差了！\n");
        if( target != me ) 
                return notify_fail("你只能提升自己的定力。\n");
        if( (int)me->query("force") < 200 )   
                return  notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("jingxing/calm") ) 
                return  notify_fail("你已经在运功中了。\n");
        
        me->add("force", -200);
        message_vision(HIR "$N深深地呼出一口气，整个人处于心神合一的境界．．．\n" NOR, me);
        me->add_temp("apply/composure", skill/10);
        me->set_temp("jingxing/calm", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/10 :), skill*3);
        me->start_busy(1);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/composure", - amount);
        me->delete_temp("jingxing/calm");
        tell_object(me, "你的静心诀运行完毕，将内力收回丹田。\n");
}
      
