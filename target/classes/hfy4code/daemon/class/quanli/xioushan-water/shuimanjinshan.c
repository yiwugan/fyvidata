 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int myexp,yourexp,extra,lvl;
        
        extra = me->query_skill("xioushan-water",1)*2; 
        if ( extra < 100) return notify_fail("你的［秀山引水功］还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［水漫金山］只能对战斗中的对手使用。\n"); 
        me->add_temp("apply/attack",extra); 
        //me->add_temp("apply/damage", extra); 
        msg = HIW  "$N"+HIW"左袖如长江翻浪，右袖如飞瀑横空，袖中突然打出一片水花，直击$n！" NOR; 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -extra); 
        //me->add_temp("apply/damage", -extra); 
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int) me->query_skill("unarmed") / 50 + 1;
        if (me->query("class")!="quanli")
                lvl = 2;
        if( random(myexp +yourexp) < myexp*lvl )
        {
                msg = HIG  "\n$N"+HIG"顺势再催内劲，水花借力飞散，点点水珠如滂沱大雨笼罩着$n！" NOR; 
                message_vision(msg + "\n", me, target);
                msg = "结果$n被$N攻了个手忙脚乱！\n";
                message_vision(msg, me, target);
                target->start_busy(3);
                me->start_busy(3);
        }else{
                me->start_busy(2); }
        return 1; 
}    
