 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
        if ( (string) me->query_skill_mapped("sword") != "feixian-sword")
        return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
        extra = me->query_skill("feixian-sword",1) / 8;
        extra += me->query_skill("feixian-steps",1) /4;
        extra = extra + (me->query("mud_age")/50000);
         
		    if ( me->query("class") != "baiyun" ) extra = extra/50;
        me->add_temp("apply/attack", extra*8);
        me->add_temp("apply/damage", extra*4);
        msg = HIR  "$N��̤�۷��ɲ����ݣ���Ѹ�ײ����ڶ�֮��ʹ���۷��ɽ������еľ��裭��������ɣ�\n���е�"+ weapon->name() + HIR"����һ�����磬�����Ļ���$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg =  HIW "����һ������ʧ��������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/6;i++)
        {
        msg = HIY "��â����ǵذ�ֱ��������\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        me->add_temp("apply/attack", -extra*8);
        me->add_temp("apply/damage", -extra*4);
        if ( me->query_busy()<2 ) me->start_busy(2);
        return 1;
}      