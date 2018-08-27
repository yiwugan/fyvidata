 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int second_sword(object me,object target,int extra,int bonus,object weapon);
int perform(object me, object target)
{
        string msg;
        int extra, bonus, rsen;
        object weapon;

        extra = me->query_skill("doomsword",1);
		    bonus = me->query_skill("doomforce",1);
        weapon=me->query_temp("weapon");

        if ( extra < 50) return notify_fail("你的寒天吹血剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［咏红梅］只能对战斗中的对手使用。\n");
        
       
       me->add_temp("apply/attack", extra*bonus/20);
        msg = HIR "$N冷然转身，口中吟出一首「咏红梅花」，正所谓红梅滴血，剑招连环掩杀而至。\n\n"+HIW"～～桃未～芳菲～杏未红" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "～～冲寒～先已～笑东风" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "～～魂飞～庾岭～春难辨" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "～～霞隔～罗浮～梦未通" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "～～绿萼～添妆～融宝炬"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "～～缟仙～扶醉～跨残虹"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "～～看来～岂是～寻常色"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "～～浓淡～由他～冰雪中～～"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -extra*bonus/20);

        if (me->query("class")=="fighter") {
       if(random(me->query("combat_exp")+extra*extra*extra)>target->query("combat_exp")){
					msg = HIC "\n最后一式剑气逼人，寒风刺骨，$N不禁打了个哆嗦。\n"NOR;
					target->start_busy(2);
					message_vision(msg, target);
        rsen = target->query("resistance/sen");
				target->set("resistance/sen",0);
                target->receive_damage("sen", extra +  random(bonus), me);
								target->set("resistance/sen",rsen);
							}
			}       
        
                 
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
        
} 
