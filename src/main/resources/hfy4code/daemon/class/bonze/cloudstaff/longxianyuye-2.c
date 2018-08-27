 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, level, dam, n;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［龙现于野］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        
        extra = me->query_skill("staff") / 2;
        level = me->query_skill("cloudstaff", 1);
        
        if (me->query("class")=="bonze") dam = extra*3/2;
                        else dam = extra;
                        
        if (level<160 && level>120 && me->query("class")=="bonze") {
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage",dam);
        msg = HIR  "$N低呼佛号，内力聚于双臂，手中的"+ weapon->name() +"幻出无数条金磷飞龙，连续两招一气呵成，狂风暴雨般地攻向$n！\n\n第一式！龙现于野！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIB  "第二式！龙腾四海！！"NOR;    
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -dam);
                me->start_busy(3);
                return 1;
        } 
        if (level<160) {
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", dam);
        msg = HIY  "$N低呼佛号，内力聚于双臂，手中的"NOR+ weapon->name() +HIY"幻出一条金磷飞龙，闪电般的扑向$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
   me->add_temp("apply/damage", -dam);     
        me->start_busy(2);
        return 1;
        }
        
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage",dam);
        msg = HIR  "$N低呼佛号，内力聚于双臂，手中的"+ weapon->name() +"幻出无数条金磷飞龙，连续三招一气呵成，狂风暴雨般地攻向$n！\n\n第一式！龙现于野！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "第二式！龙腾四海！！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC  "第三式！龙翔九天！！！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -dam);
                me->start_busy(3);
                return 1;
                
}      
