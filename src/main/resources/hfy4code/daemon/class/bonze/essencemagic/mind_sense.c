 // mind_sense.c
#include <ansi.h>
inherit SSERVER; 
int conjure(object me, object target)
{
        string msg;
        int damage, ap, dp; 
        if(me->query("class")!="bonze" && me->query("class")!="yinshi" )
                return notify_fail("ֻ�еõ���ɮ����������ʿ�ſ���ʹ����ʶ��ͨ��\n");
        if((int)me->query_skill("essencemagic",1) < 40)
                return notify_fail("��ķ��������ߣ�\n");
               
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if((int)me->query("atman") < 80 )
                return notify_fail("��ķ���������\n"); 
        me->add("atman",-80);
        
        msg = HIC "$N��Ŀ����ӡ�÷���һ����â����$n��\n\n" NOR;
        //  400*3= 1200, total damage 1200 +random(1200)
        damage = me->query_skill("magic")*3;
        dp = target->query("combat_exp");
        ap = me->query("combat_exp");
        
        if( random(ap *3 )+ap/2 > dp ) {
                damage = damage + random(damage);
                msg +=  HIY "��â��$p"+HIY"����͸��������ϳ�һ������������ֱ�䵽��������ĵ��£�\n" NOR;
                target->receive_damage("gin", damage, me);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,damage);
        } else
                {       msg += HIB"���Ǳ�$n"HIB"�㿪�ˡ�\n\n"NOR;
                        message_vision(msg, me, target);
                        }
        if (me->query_busy()<2) me->start_busy(2);
        
   return 1;
}     
