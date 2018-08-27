#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int your_exp,n;
        int i;
        
        if (me->query_skill("liangyi-force")<60)
                return notify_fail("［如封似闭］需要至少60级两仪心法。\n");
        
//      if(me->query_skill_mapped("force") != "liangyi-force") 
//              return notify_fail("［如封似闭］需要两仪心法的配合。\n");
        
        if (me->query("force")<100)
                return notify_fail("你的内力不够。\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
                ||!target->is_character()
                ||!me->is_fighting(target) )
                return notify_fail("［如封似闭］只能对战斗中的对手使用。\n"); 
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
    
        message_vision("$N"+CYN"使出两仪心法中一招“如封似闭”，右脚实，左脚虚，粘连粘随，
左掌搭住"+"$n"+CYN"右腕，横劲发出。\n"NOR, me, target);
        me->start_busy(1);      
        if (userp(me)) me->add("force",-100);
        
        your_exp= target->query("combat_exp")/3;              
        if(random(me->query("combat_exp")+me->query("combat_exp")/9) > your_exp)        
        {
        message_vision("\n$N"+CYN"身不由主的向前一冲，跨出两步，方始站定！\n"NOR,target);
        n= me->query_skill("liangyi-force", 1)/60;
        target->start_busy(1+random(n));
        } else message_vision(WHT"可是"+"$n"+WHT"看破了"+"$N"+WHT"的企图，并没有上当。\n"NOR, me, target);
        return 1;
}     
