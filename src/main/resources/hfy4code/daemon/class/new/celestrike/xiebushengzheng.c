 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,extra,skill; 
        extra=me->query_skill("celestial",1);
        skill=me->query_skill("celestrike",1);
        if(me->query("m_success/结拜郭大路")==0)
                skill/=100;
                else skill*=10;
        if(skill<20)
                return notify_fail("你天邪掌法的修为还不够高。\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［邪不胜正］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");        
        if(me->query("m_success/结拜郭大路")==0)
                extra/=100;
                 else extra*=10;                
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        if (target->query("boss")|| target->query("big_boss")) yourexp=yourexp*8;
//      (200/2+1.2x160) =292/40+1 = 8
        lvl = skill * extra;
        
        msg = HIW "天邪掌法独具一格，只见一招［邪不胜正］尽显精髓，$N以连绵不绝的掌势击向$n！" NOR;
        if( random(yourexp) - lvl * lvl < myexp + lvl*lvl )
        {
                message_vision(msg + "\n", me, target);
                msg = "结果$n被$N的掌势所困，犹豫不决！\n";
                message_vision(msg, me, target);
                if(me->query("class") != "fugui") {target->start_busy(2);}
                else {target->start_busy(3);}
                me->start_busy(1);
        }
        else
        {
                me->add_temp("apply/attack",extra*2);
                me->add_temp("apply/damage",skill*2);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
           me->add_temp("apply/attack",-extra*2);
           me->add_temp("apply/damage",-skill*2);
                if (me->query_busy()<2) me->start_busy(2);
        }
        return 1;
}
