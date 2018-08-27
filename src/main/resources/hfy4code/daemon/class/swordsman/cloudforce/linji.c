 // fyteam

inherit SSERVER;
#include <ansi.h> 
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)

{
    int skill;
    if( target != me ) 
        return notify_fail("你只能将［云次鳞集］用在自己的身上。\n");
	        if(me->query("class")!="swordsman")
                return notify_fail("神剑只有剑神的弟子才有资格用！\n");
    if( (int)me->query("force") < 50 )     
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("parryup") ) 
        return notify_fail("你已经在施展类似的武功了。\n");
        skill = me->query_skill("cloudforce", 1);
        if(skill < 50) {
                return notify_fail("你的淡云心法太差了！\n");
         }
         me->add("force", -50);
     tell_object(me, HIW"你气沉丹田，劲逼任督，三花聚顶，顿时感觉到身形灵敏了许多。\n"NOR);
     message("vision", HIW"忽然之间，" + me->name() + "驻足运气，身形似乎更稳了，但动作却又更快了。\n"NOR,
                environment(me), me);
                
     if (me->query("class")=="swordsman")  skill=(skill+random(skill))/2;
        else skill=skill/50;
     me->add_temp("apply/parry", skill);
        
     me->set_temp("parryup", 1);
     me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
     if( me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/parry", - amount);
        me->delete_temp("parryup");
        tell_object(me, "［云次鳞集］气劲耗尽，似乎不如刚才敏捷了。\n");
}
  
