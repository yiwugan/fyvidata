#include <ansi.h>
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        object weapon; 
        extra = me->query_skill("snake-spear",1); 
          if ( extra < 50) return notify_fail("����ߴ̻��������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("�۽��߿����ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon"); 
        msg = HIY  "$N������۽��߿���ݣ�ȼ���ޱ�ս�⣬���е�"+ weapon->name()+  "��������$n������һǹ��"NOR; 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIW  "�ڶ�ǹ��"NOR; 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIC  "����ǹ��"NOR; 
        me->start_busy(5); 
        return 1; 
}  
