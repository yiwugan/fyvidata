#include <ansi.h>
inherit SSERVER; 
int main(object me, string arg)
{
        object room;
        int marktime1;
		if( me->query("class") != "wudang" ) 
				return notify_fail("只有武当弟子才能使用这个命令！\n");
        if((int) me->query_skill("incarnation",1) < 160)
                return notify_fail("你的修仙术不够高深！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中无法使用仙法！\n");
        if( me->query("atman") < 50 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 100 )
                return notify_fail("你的精不够！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法使用仙法！\n");     
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("此地不能使用时空转换。\n");
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("此地不能使用时空转换。\n"); 
        me->add("atman", -50);
        me->receive_damage("gin", 100);
        me->start_busy(1);
        message_vision( MAG "$N环顾四方，双手一挥，闪出一点紫色火花落入地上消失了 。。。。\n" NOR, me);
        room = environment(me);
        marktime1=1500+random((me->query_skill("incarnation",1)-80)*100);
        me->set_temp("timespacemark1",base_name(room));
        me->set_temp("timespacemark_time1",time()+marktime1);
        return 1;
}     
