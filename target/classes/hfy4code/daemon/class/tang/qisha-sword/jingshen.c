 // tanzhijinghun.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target) {
        
        string msg;
        int bonus, damage_bonus, damage, level, lvl;
        
        if(!objectp(target)) target = offensive_target(me);
        
        if (me->query_skill("qisha-sword",1)<50) 
                return notify_fail("你的「七杀剑法」不够熟练！\n");
        
        if( !target ) target = offensive_target(me);
        if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
                return notify_fail("「七煞惊神」只能对战斗中的对手使用。\n");
        }
        
        if(target->is_busy()) {
                return notify_fail("对方已经不能动弹了。。。\n");
        }
        
        bonus = (int) me->query_skill("qisha-sword",1);
        lvl = (int) me->query_skill("dujing-force",1);
        
        me->add_temp("apply/attack",bonus);
        me->add_temp("apply/damage",bonus+ lvl);
        
        msg = HIW  "\n$N身形一顿，竟然使出唐门失传已久的「七煞惊神」，一招连环七式！！！\n\n"NOR;
        msg+=HIC"第一式！直刺曲池！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   
        msg = HIC"第二式！反插太乙！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        msg = HIC "第三式！下袭血海！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       
		    msg = HIC  "第四式！横扫少冲！" NOR;
		    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    
        msg = HIC  "第五式！力逼耳门！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
     
        me->add_temp("apply/attack",-bonus);
        me->add_temp("apply/damage",-bonus-lvl);
 
 msg = HIC"\n$N"+HIC"最后孤注一掷，第六、第七式连环施出，点向"+"$n"+HIC"期门、立关两处要穴。\n"NOR;
        bonus = ((int) random(me->query("combat_exp")/40*lvl)+me->query("combat_exp")/4)/((int) target->query("combat_exp")+1);
                if(bonus >= 1) {
                msg += HIG"$n"+HIG"只觉几大穴道一麻，登时动弹不得。\n" NOR;           
                damage = me->query_skill("throwing")>=420?420:me->query_skill("throwing");
                damage_bonus=me->query("combat_exp")/3000*damage/1000;
                if (damage_bonus>damage*3/2) damage_bonus= damage*3/2; 
                damage = damage+ damage_bonus;
                target->receive_damage("kee", damage, me);
                target->start_busy(3);
        
                        msg += WHT"$N"+WHT"内力流转，身法居然少见滞涩！\n"NOR;
                        me->start_busy(1);
        
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
        } else {
                msg += YEL"\n$n"+YEL"就地一滚堪堪躲过了$P"+YEL"的攻击！！\n"NOR;
                message_vision(msg, me, target);
                me->start_busy(3);
                }
 
    me->start_busy(2);

    return 1;
                
}   
