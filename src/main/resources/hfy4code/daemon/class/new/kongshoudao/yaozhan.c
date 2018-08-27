 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int orforce; 
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［腰斩］只能对战斗中的对手使用。\n");
        extra = me->query_skill("kongshoudao") ;
        if(extra < 100 ) return notify_fail("你的［空手道］不够熟练！\n");
        me->add("force_factor",extra/4); 
        orforce = (int) me->query("force"); 
        me->add("force",extra/3*10); 
        msg = HIR "$N突然绕到$n身后，右膝猛然上顶，双手同时抓向$n，企图将$n的后腰磕断！" NOR;
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->set("force_factor",0); 
        me->set("force", orforce); 
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
        me->start_busy(2);
        return 1;
}     
