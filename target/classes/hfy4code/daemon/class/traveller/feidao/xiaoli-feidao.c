 // counterattack.c
#include <ansi.h> 
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("С��ɵ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int) me->query_skill("feidao",1) <= 300)
                return notify_fail("��ķɵ��������������������ܷ���С��ɵ���\n"); 
        message_vision(RED"$NĿ��ת���ض���$n��׼����������һ����\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(3)+3);
        me->start_busy(random(5));
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target) && !target->query("NODIE"))
        {
msg = HIY "$Nʹ���ɵ������������鷢��" + HIR "С��ɵ�" +HIY "��$nֻ������ǰһ�����ʺ��ѱ��Դ�����������" ;
msg +=  "\nһ��Ѫ����ӿ��������$n���۾�������ͻ�˳�������\n" NOR; 
        message_vision(msg, me, target);
                target->die();
        }
        else
                {
                msg= CYN"��$n"+NOR CYN"�������磬�Ǳ��ػ�ס���ţ����㵲ס��$N"+NOR CYN"�������һ�У�\n"NOR;
                COMBAT_D->do_attack(me,target,TYPE_PERFORM, msg);
                if (me->query_busy()<3) me->start_busy(3);
                } 
        	
        return ;
}     
