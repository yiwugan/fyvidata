 // 幻影千重
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,n, myexp;
        extra = me->query_skill("meng-steps",1);
        if ( extra < 100) return notify_fail("你的［幻梦步法］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［幻影千重］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
        if (me->query("class")=="bat" && extra >=170) n=0;
                else n=10;
        if(me->query_temp("huanyinqianchong")+n>time() && userp(me))
                return notify_fail("你刚刚施展过［幻影千重］！！\n");   
        message_vision(HIR"$N"+HIR"的身影突然一变十、十变百、百变千，"+HIR"$n"+HIR"早被"+HIR"$N"+HIR"的千重幻影围住！\n" NOR,me,target);
        myexp=random(me->query("combat_exp")*3);
        if (me->query("class")=="bat")
                myexp=myexp+me->query("combat_exp")/5;
                
        if((int)target->query("combat_exp") < myexp)
        {
        message_vision(HIW "结果"+HIW"$N"+HIW"目眩神弛，心惊肉跳！\n" NOR,target);
        target->start_busy(3);
        me->set_temp("huanyinqianchong",time());
        }
        else{
        message_vision(YEL"结果"+YEL"$N"+YEL"并不被幻影所扰乱！\n"NOR,target);
        me->start_busy(2);
        }
        return 1;
}   
