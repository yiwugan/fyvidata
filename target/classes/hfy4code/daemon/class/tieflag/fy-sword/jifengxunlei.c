#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,skill;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("fy-sword", 1);
        skill = extra;
        if ( userp(me) && (me->query_skill_mapped("force") != "cloudsforce" && me->query_skill_mapped("force") != "jiayiforce" && me->query_skill_mapped("force") != "tiexue-force"))
                return notify_fail("�ۼ���Ѹ�ף���Ҫ��Ѫ�����ŵ��ķ���ϣ�\n");
        if ( extra < 50) return notify_fail("��Ĵ�����ƽ����������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۼ���Ѹ�ף�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        i = extra/40+random(extra/60);
        if(i<4)i=4;
        if(me->query_skill_mapped("force") == "jiayiforce" && me->query_skill("jiayiforce", 1) >= 100)
         extra*=5/3;


        msg = HIR  "$N����һչ��ͻȻʹ��������ƽ��ľ��Уۼ���Ѹ�ףݣ�������â�����Ǹ��°㹥��$n��\n" NOR;
        message_vision(msg,me,target);
        if(skill>=120)
        {
        msg = YEL"�������ݺύ�����ɫ��âֱ��$n��$lϮȥ��" NOR;
	  extra*=3/2;
        }
        else
        {
        msg = WHT"һ˿˿�������޵Ľ�â����$n��$l��" NOR;
        }        
        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);
        while(i>0)
        {
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        i--;
        }
        if(me->query_temp("tiexue"))
        {
        me->add_temp("apply/damage",extra*5);
        me->add_temp("apply/attack",extra*5);
        if(skill>=120) msg = YEL"$N���һ�������г�������һ�����磬Ѹ���ޱȵش���$n��$l��" NOR;
        else msg = WHT"$N������ǰ��������ת�����$n��$l" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*6);
        me->add_temp("apply/attack",-extra*6);
        }
        else
        {
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);
        }
        if ( me->query_busy()<3 ) me->start_busy(3);
        return 1;
}    
