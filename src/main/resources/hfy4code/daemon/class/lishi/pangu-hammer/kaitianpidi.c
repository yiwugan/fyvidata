 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query("force");
        if ( extra < 300) return notify_fail("�������̫���������ò����ۿ���ٵأ�����У�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۿ���ٵأ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        me->add_temp("apply/damage", extra);
        msg = HIY  "$N�߸ߵþ������е�"+ weapon->name()+  "��ȫ��֮��������$n��Ȼ���£�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->set("force",((int)me->query("force"))*2/3);
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        return 1;
}    
