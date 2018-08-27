#include <ansi.h>
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        object weapon; 
        extra = me->query_skill("snake-spear",1); 
          if ( extra < 50) return notify_fail("你的蛇刺还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［金蛇狂舞］只能对战斗中的对手使用。\n"); 
        weapon = me->query_temp("weapon"); 
        msg = HIY  "$N对天狂吼［金蛇狂舞］，燃起无边战意，手中的"+ weapon->name()+  "毒龙般向$n攻出第一枪！"NOR; 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIW  "第二枪！"NOR; 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIC  "第三枪！"NOR; 
        me->start_busy(5); 
        return 1; 
}  
