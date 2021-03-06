 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int myexp,yourexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("wind-blade",1);
		if( extra < 120) return notify_fail("你的『迎风一刀斩』还不够纯熟！\n");
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［雷霆霹雳］只能对战斗中的对手使用。\n");

		message_vision(HIW"$N气势大涨，手中的"+ weapon->name() +HIW"幻出漫天刀云。\n"NOR, me);
//		yourexp = random( target->query("combat_exp") );
		yourexp = target->query("combat_exp");
		myexp = me->query("combat_exp")*(extra/220);
		if( yourexp < myexp )
        {
                message_vision(HIY"$N"+HIY"被这磅礴的气势所震，不由得心惊肉跳！\n"NOR,target);
                if(target->query_busy()<3) target->start_busy(3);
        }
        else{
        message_vision(YEL"但是$N"+NOR YEL"并不为$n"+NOR YEL"的气势所动！\n"NOR, target, me);
        }
		extra = me->query_skill("blade");
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra*3);
        msg = HIW"只见$N的"+weapon->name() +HIW"划破刀云，雷霆霹雳般地击向$n！"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra*3);
        if (me->query_busy()<2) 
                me->start_busy(2);
        return 1;
}    
