 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i;
        object weapon;
        if(me->query("class")!="yinshi")
                return notify_fail("只有帝王谷弟子才会［开天辟地］。\n");
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        if (me->query_skill("pangu-hammer",1)<100)
                return notify_fail("你的盘古锤法不够娴熟。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［开天辟地］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        extra = me->query("force");
        if ( extra < 300) return notify_fail("你的内力太弱，还运用不出［开天辟地］这绝招！\n");
        i = random(10);
//      if (i && userp(me)) target->add_temp("apply/dodge",me->query_skill("pangu-hammer",1)*3);                
        me->add_temp("apply/damage", extra);
        msg = HIY  "$N高高得举起手中的"+ weapon->name()+  "集全身之内力，向$n猛然挥下！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
//      if (i && userp(me)) target->add_temp("apply/dodge",-me->query_skill("pangu-hammer",1)*3);
        if (userp(me)) me->set("force",((int)me->query("force"))*2/3);
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        return 1;
}      
