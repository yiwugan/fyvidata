 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［九重寒天掌］只能对战斗中的对手使用。\n");
        extra = me->query_skill("doomstrike",1)/2;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra*2);
        msg = HIR  "$N使出［九重寒天掌］，全身飞速旋转，双掌一前一后，闪电般的击向$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra*2);
        me->start_busy(2);
        return 1;
}  
