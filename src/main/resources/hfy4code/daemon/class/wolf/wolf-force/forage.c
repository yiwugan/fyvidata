 // forage.c
// Created by Silencer 
#include <ansi.h> 
int exert(object me, object target)
{
        int lvl;
        object fruit;
        if (me->query("class")!="wolfmount")
                return notify_fail("只有狼山弟子才能有效地采集食物。\n");
        if (environment(me) && !environment(me)->query("outdoors"))
                return notify_fail("你只能在室外采集食物。\n");
        if (me->query_skill("wolf-force",1)<50)
                return notify_fail("你的天狼心法太差了。\n");
        if( me->is_fighting())
                return notify_fail(HIR "战斗中无法分心采集食物！\n"NOR);
        
        if( (int)me->query("timer/forage")+20 > time() )
                return notify_fail("你太累了，先休息一会儿再说吧。\n");
        
        me->set("timer/forage",time());
        message_vision("$N四处张望，寻找可以果腹之物。\n",me);
        
        lvl= me->query_skill("wolf-force",1);
        if (random(lvl)<25)
                return notify_fail("你什么也没找到，白忙乎了一场。\n");
        seteuid(getuid());
        fruit= new("/obj/specials/wolfitem/wolf_fruit");
        fruit->move(me);
        tell_object(me,"你找到了一些野果。\n");
        return 1;
}   
