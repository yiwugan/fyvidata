 // fyteam
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("你只能将［无物无我］用在自己的身上。\n");
    if( (int)me->query("force") < 100 )     
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("stepup") ) 
        return notify_fail("你已经在施展类似的武功了。\n");
        skill = me->query_skill("puti-steps", 1);
        if(skill < 80) {
                return notify_fail("你的菩提虚空步法太差了！\n");
         }
         me->add("force", -100);
     tell_object(me, HIG"你摒除心中所有杂念，只感到灵台一片明净，霎时间身轻似无物。\n"NOR);
     message("vision", HIG"只见" + me->name() + "面色庄重，不为外界事物所干扰，身形也陡然加快。\n"NOR,
                environment(me), me);
                
     if (me->query("class")=="shaolin")  skill=skill;
        else if (me->query("class")=="official")  skill=skill;
             else skill=skill/2;
     me->add_temp("apply/dodge", skill);
        
     me->set_temp("stepup", 1);
     me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
     if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("stepup");
        tell_object(me, "你的［无物无我］施展完毕，身形稳定了下来。\n");
}
  
