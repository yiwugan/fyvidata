 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, power,nd;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۰�ѩ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("snowshade-sword",1);
        power = me->query_skill("scratching",1);
        if (me->query("class")=="taoist" && me->query_skill("scratching")) {
                power=me->query_skill("scratching");
                }
        nd=me->query("no_dodge_snow");
        me->delete("no_dodge_snow");

        msg = HIW  "$N���е�"+ weapon->name() +"���������ѩ��һ���׹�����������$n��\n"NOR;
		if(random(me->query("combat_exp")+extra*extra*extra)>target->query("combat_exp")/2) {
			msg += HIW"����Ű�ãã�����磬$n"+HIW"��֪���������ģ��������" NOR;
            target->receive_damage("sen", 10 + power + random(power*2), me);
		}
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra+power);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra-power);
        if (me->query_busy()<2) me->start_busy(2);
        me->set("no_dodge_snow",nd);
        return 1;
}   
