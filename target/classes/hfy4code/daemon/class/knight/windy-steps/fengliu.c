#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,myexp,yourexp,cpexp;
//      if(me->query("class")!="knight")
//              return notify_fail("只有快活林弟子才能使出「风流」的绝技。\n");
        extra = me->query_skill("windy-steps",1);
        if ( extra < 50) return notify_fail("你的［急风三十六式］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［风流］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
        if (target->query("step_less")==1) 
                return notify_fail(HIW"此人身势灵活，功力深湛，不会被此步法迷惑的。\n"NOR);
        
        message_vision(HIY"$N"+HIY"『风流』无限，衣襟浮动，仿佛风卷残云，环绕着$n"+HIY"陀螺般愈转愈快！\n"NOR,me,target);
        
        yourexp=(int)target->query("combat_exp");
        myexp= (int)me->query("combat_exp");
        cpexp= myexp/2+random(myexp)+extra/50*random(myexp)/2;
        if(me->query("class") != "knight" && userp(me)) cpexp=random(myexp)*2;
        if( yourexp<cpexp )
        {
                message_vision(HIG"结果$N"+HIG"被扰得眼花潦乱，接应不暇！\n"NOR,target);
                target->start_busy(2+random(2));
        }
        else{
                message_vision(HIW"结果$N"+HIW"自己转了个头晕眼花！\n"NOR,me);
                me->start_busy(2);
        }
        return 1;
}    
