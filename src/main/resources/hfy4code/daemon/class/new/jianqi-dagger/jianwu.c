 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra,skill; 
        object weapon; 
        if(me->query("gender")!="女性")
                return notify_fail("你堂堂一个大男人怎麽能用「剑舞」？！\n");
        extra = me->query_skill("jianqi-dagger",1); 
        skill = me->query_skill("dagger"); 
        if ( extra < 70) return notify_fail("你的［红绸剑器］还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me); 
        if (me->query("class")== 0 )skill = extra + skill;
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［剑舞］只能对战斗中的对手使用。\n"); 
        weapon = me->query_temp("weapon"); 
		message_vision(HIM"$N"HIM"长袖善流，飞跃而起，在曼妙的歌声中使出——『剑舞』！\n"NOR, me);
        if(random((int)me->query("combat_exp")*(skill/100+extra/100)) > (int)target->query("combat_exp") && !target->is_busy())
        {
        msg = HIR"$N"HIR"手中的" + weapon->name() + HIR"化作千千万万的无形剑气向$n"HIR"刺去！\n"HIW"$n"HIW"情不自禁地受歌舞迷惑，忘记了进攻。\n"NOR;        
        target->start_busy(5);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        }
        else{      
			msg = HIR"$N"HIR"手中的" + weapon->name() + HIR"化作千千万万的无形剑气向$n"HIR"刺去！\n"NOR;
        me->add_temp("apply/damage", 5*extra); 
        me->add_temp("apply/attack", 5*skill); 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage", -5*extra); 
        me->add_temp("apply/attack", -5*skill); 
        }
       if(me->query_busy()<3) me->start_busy(3);
        return 1;
}     
