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
        
        extra = (me->query_skill("sword") + (me->query("mud_age")/50000));
        
        if (me->query_temp("apply/painting"))extra *= 2;
        
		if(me->query("class") != "baiyun") extra /= 5;
        
        me->add_temp("apply/attack", extra*3);    
        me->add_temp("apply/damage", extra*3); 
        weapon=me->query_temp("weapon");
        
        msg = HIY  "$Nʹ�����ɽ����еľ��裭����������ɣ�\n���е�"+ weapon->name() + HIY"����һ�����磬�����Ļ���$n��" NOR;
        msg += HIW "�����������������췱�ǡ�\n" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);

        me->add_temp("apply/attack", -extra*3);
        me->add_temp("apply/damage", -extra*3);
        if ( me->query_busy()<2 ) me->start_busy(2);
        return 1;
}  