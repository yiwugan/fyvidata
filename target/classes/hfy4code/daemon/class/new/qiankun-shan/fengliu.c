#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("qiankun-shan",1) ;
        if ( extra < 50) return notify_fail("���Ǭ�������Ȳ������죡\n");
        if(me->query_skill("qiankunstrike",1)> 1)    extra = extra *5;
              //    if( me->query_temp("parryup") ) extra = random(extra)*2+extra;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷������Ĺ��˼��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
               // me->set_temp("14sword",1);
        {
        me->add_temp("apply/attack", extra*5);
        me->add_temp("apply/damage", extra*5);
        msg = HIC"$NͻȻ������Ц������һת����������������Ц��̫��񲣬��Ц���˿������������� \n"
        HIC "ֻ���������һ�У������ݺύ��������������� \n"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*5);
        me->add_temp("apply/damage", -extra*5);
        if (me->query_busy()<2) me->start_busy(2);
                //me->set_temp("14sword",0);
        }
        return 1;
}      
