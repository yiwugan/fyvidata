#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
extra = me->query_skill("yue-strike", 1);
        if ( extra < 50) return notify_fail("���С��ɽ�ƻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۹ʹ����Σ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/damage",extra/2);
        me->add_temp("apply/attack",extra/4);
        msg = HIY  "$N���쳤Ц��ʹ����С��ɽ�Ƶģ۹ʹ����Σݣ�һ�ɺ�Ȼ����ֱ��������\n" NOR;
        message_vision(msg,me,target);
        msg = HIR  "��" NOR;
                msg+= "\n$N�����ھ���˫�������ֱȡ$n��$l��";
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIW  "      ��" NOR;
                msg+= "\n$N�ұ��绷��Ȧס$n���ֱۣ����ֺ���������һȭ����$p��";
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIM  "            ��" NOR;
                msg+= "\n$N������磬ת�ۼ�˫���Ѿ�������$n����ǰ��";
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIB  "                  ��" NOR;
                msg+= "\n$N����һ�ۣ�����»���$n��ֱ����֪����ζ�ܣ�";
                me->add_temp("apply/damage",extra/2);
                me->add_temp("apply/attack",extra/4);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->start_busy(2);
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra/2);
        return 1;
}    
