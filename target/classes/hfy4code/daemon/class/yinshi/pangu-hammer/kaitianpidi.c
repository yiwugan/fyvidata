 // tie@fengyun
#include <ansi.h>
#include <combat.h>
//inherit NPC;
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i;
        object weapon;
        if(me->query("class")!="yinshi")
                return notify_fail("ֻ�е����ȵ��Ӳ���ʹ�ۿ���ٵأݡ�\n");
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        if (me->query_skill("pangu-hammer",1)<100)
                return notify_fail("����̹Ŵ���������졣\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۿ���ٵأ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        extra = me->query("force");
        if ( extra < 300) return notify_fail("�������̫���������ò����ۿ���ٵأ�����У�\n");
        
        me->add_temp("apply/damage", extra);
        msg = HIY  "$N"+HIY"�߸ߵؾ������е�"+ weapon->name()+ HIY"��ȫ��֮��������$n"+HIY"��Ȼ���£�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        if (userp(me)) me->set("force",((int)me->query("force"))*2/3);
        me->add_temp("apply/damage", -extra);
        if (me->query_busy()<2) me->start_busy(2);
        return 1;
}
