 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,skill;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ʮ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                skill=(int) me->query_skill("yunwu-strike",1);
                lvl = (int) me->query_skill("unarmed")  ;
                myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp") ;
                        if (me->query("class")!="huangshan") skill = skill*48;

        msg = HIY "$Nʹ�������Ʒ��еģ�ʮ������ݣ�˫�ƻ��裬��Ӱ�ܲ���������$n��" NOR;
        if( lvl * myexp   >  (random(skill)/2+skill) * yourexp )
        {
                message_vision(msg + "\n", me, target);
                msg = "���$n��$N���˸���æ���ң�\n";
                message_vision(msg, me, target);
                target->start_busy(3+lvl/30);
        }
        else
                        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                        me->start_busy(2);
        return 1;
}      
