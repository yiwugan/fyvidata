#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int add_agi, bonus;
        int my_exp, your_exp;
        if(me->query("class")!="yinshi")
                return notify_fail("只有帝王谷弟子才能下降头。\n");
        //if( !target ) target = me;
        if((int)me->query_skill("celecurse",1) < 20 )
                return notify_fail("你的降头术不够高！\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
                ||!target->is_character()
                ||target->is_corpse()
                ||target==me)
                return notify_fail("你要对谁施展这个降头？\n");
        if(target->query("possessed")!= me )
        	      return notify_fail("你只能送走自己制造的亡灵！\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不够！\n");
                
        me->receive_wound("kee", random(100));
        msg = HIR "$N眼内突然闪过一丝血光，随即突然冒出一股浓雾，将亡灵卷走．．．\n\n" NOR;
        message_vision(msg, me);
        me->delete_temp("timer/solidghost");
        destruct(target); 
        return 1;
} 
