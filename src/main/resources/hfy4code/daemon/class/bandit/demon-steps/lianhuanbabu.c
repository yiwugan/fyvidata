 // ice@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp, extra, bonus;
        extra = me->query_skill("demon-steps",1);
		bonus = me->query_skill("demon-force",1);
        if ( extra < 30) return notify_fail("��ģ�������ħ�����˲��ݻ��������죡\n");
        if (( extra <= 100)&& me->query("bellicosity")< 200 && userp(me) ) return notify_fail("���ɱ�������ߡ���Ҫ����ɱ����\n");
      if ((extra > 100)&&(extra <= 160)&& me->query("bellicosity")< 300 && userp(me) ) return notify_fail("���ɱ�������ߡ���Ҫ����ɱ����\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������˲���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");

        message_vision(HIB"\n$N"+HIB"����������ħ�����˲�����ʮ��ʽ����ʩչ��Χ��$n"+HIB"ת����ͣ��\n"NOR, me, target);
		myexp = (me->query("combat_exp")/50)*(extra/50)+(random(me->query("combat_exp") / 50)*extra);
		if( me->query("class")=="bandit" && me->query_skill_mapped("force") == "demon-force" && extra >100 && bonus> 100 ) {
			message_vision(HIB"$N"+HIB"�߶������������������죡\n"NOR, me);
			myexp = (me->query("combat_exp")/50)*extra+ (random(me->query("combat_exp"))/ 80) * bonus+extra*bonus;
		}

        if( myexp*2/3+random(myexp/3) > target->query("combat_exp") )
        {
        message_vision(HIW"$N"+HIW"���ŵ���æ���ң������ٳ���\n"NOR, target);
        target->start_busy(3);
        }
        else{
        message_vision(BLU"����$N"+NOR BLU"�Ծ��ƶ����������ң�\n"NOR, target);
        me->start_busy(2);
		}
        return 1;
}   
