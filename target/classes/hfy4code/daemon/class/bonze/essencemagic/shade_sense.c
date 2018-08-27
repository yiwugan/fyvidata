 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int conjure(object me, object target)
{
        int lvl,i;
        object env, *inv; 
if(me->query("class")!="bonze" && me->query("class")!="yinshi" )
                return notify_fail("只有得道高僧或者隐世居士才可以使用隐识神通！\n");
        
        lvl = (int) me->query_skill("magic");
        if ( lvl <= 200)
                return notify_fail("你法术不够高！\n");
        
        if( me->query("atman") < 100 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 50 )
                return notify_fail("你的精不够！\n");
        
        if(me->query("env/invisibility"))
                return notify_fail("你正在施展［隐识］\n");
        
        me->add("atman", -100);
        me->receive_damage("gin", 50);
        
        message_vision(HIW "$N凝神提气，一团白芒乍出体内，整个人渐渐虚化．．．\n" NOR, me);
        me->start_call_out( (: call_other, __FILE__, "take_effect", me :), 5);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 20+lvl/10+3*random(lvl/10));
        if( me->is_fighting() ) me->start_busy(3);
        return 1; 
}
void remove_effect(object me)
{
        me->set("env/invisibility", 0);
        message_vision(HIG "$N的身形渐渐地显现出来。\n" NOR, me);
        me->move(environment(me));
        me->start_busy(1);
        tell_object(me,YEL"你的隐识失效了。\n"NOR);
} 
void take_effect (object me)
{
        me->set("env/invisibility", 1);
        tell_object(me,YEL"你的隐识成功了。\n"NOR);
        
} 
        
       
