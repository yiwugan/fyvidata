//springrain-blade.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 int extra; 
 object weapon;
 if(me->is_busy())
  return notify_fail("你现在没空！！\n");
 extra = me->query_skill("blade"); 
 if (me->query("class")== "swordsuper") extra = extra * 8;
        if (me->query("class")=="legend") extra = extra * 2;
        if (me->query("class")=="tieflag") extra = extra * 3;
        if (me->query("class")=="huangshan") extra = extra * 6;
        if (me->query("class")=="yinshi") extra = extra * 5;
 if ( me->query_skill("springrain-blade",1) < 120 && userp(me)) 
     return notify_fail("你的春雨刀法不够纯熟。\n");
 if( !target ) target = offensive_target(me);
 if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［当时明月］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",extra/3);
        me->add_temp("apply/damage",extra/5);
        weapon = me->query_temp("weapon");
        msg = HIC  "\n$N轻叹一声，随手挽了个刀花，"+ weapon->name()+HIC"斜斜挥出，却是『春雨刀法』中的精髓之式"HIY"「当时－明－月－」"+HIC"！\n" NOR;
        message_vision(msg,me,target);
        msg = HIC"              当   "HIY"             曾" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"              时   "HIY"             照" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"              明   "HIY"             彩" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"              月   "HIY"             云" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"              在   "HIY"             归" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->start_busy(3);
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra/5);
        return 1;
}    
