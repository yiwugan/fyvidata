 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra,dodge; 
        object weapon; 
        if (me->query("class")!="quanli")
                return notify_fail ("［梅开五度］只有财神庙的兄弟姐妹才能使用。\n");
        dodge = me->query_skill("stormdance",1); 
        extra = me->query_skill("zhao-sword",1); 
        if ( extra < 30) return notify_fail("你的五展梅剑法还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［梅开五度］只能对战斗中的对手使用。\n"); 
        extra +=dodge;
        me->add_temp("apply/attack", extra);
        msg = HIG "$N微微一笑，猛吸一口气,欲使出以气驭剑绝技攻击$n。\n"+HIW"第一剑！梅花初绽！" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "第二剑！梅开二度！" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "第三剑！朵朵寒梅！" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "第四剑！嘘寒问暖！" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "第五剑！梅花消逝！"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -extra);
        me->start_busy(2); 
        return 1; 
}      
