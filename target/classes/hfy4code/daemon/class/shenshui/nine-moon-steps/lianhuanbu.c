 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
//      if(me->query("class")!="shenshui")
//              return notify_fail("只有神水宫弟子才能使出「连环步」的绝技。\n"); 
        extra = me->query_skill("nine-moon-steps",1);
        if ( extra < 30) return notify_fail("你的［九阴身法］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［连环步］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
        
        message_vision(HIM"$N脚踩连环，环绕着$n转个不停！\n"NOR,me,target);
        if(random((int)target->query("combat_exp")*2) < (int)me->query("combat_exp")+extra*extra*extra)
        {
                message_vision(YEL"        结果$N被扰得眼花潦乱，接应不暇！\n"NOR,target);
                target->start_busy(2+random(extra/60));
        }
        else{
        message_vision(BLU"       结果$N自己转了个头晕眼花！\n"NOR,me);
                if(me->query("class")!="shenshui") me->start_busy(2);
                else me->start_busy(1);
        }
        return 1;
}   
