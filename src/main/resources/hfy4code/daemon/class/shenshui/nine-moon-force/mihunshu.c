 // silencer@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target, int amount)
{
        int skill, per, base;
        
        if(me->query("class") != "shenshui")
                return  notify_fail("���Ի�󷨣�����ˮ���ľ�����\n");
        if (me->query_skill("nine-moon-spirit",1)<50)
                return notify_fail ("���[�Ů��]̫���ˡ�\n");
        if (me->query_skill_mapped("force") != "nine-moon-force")
                return notify_fail("���Ի�󷨡���Ҫ�����ľ�����ϡ�\n");
        if((int)me->query("timer/mihunshu") + 14 > time())
                return notify_fail(HIM"���Ի�󷨡���������ʹ�á�\n"NOR);
        if( !me->is_fighting() )
                return notify_fail("���Ի�󷨣�ֻ����ս����ʹ�á�\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("�������������\n"); 
                
        if( !target || target==me ) target = offensive_target(me);
        if (!target) return notify_fail("��Ҫ��˭ʩչ���Ի�󷨣ݣ�\n");
        
        skill = me->query_skill("nine-moon-spirit",1);
        me->add("force", -100);
        per = me->query("per");
        message_vision(
                
                HIG"\n$Nͣס���֣���ƮƮ���۹����������$n"+HIG"��������˿����Цӯӯ ...\n\n"NOR
                WHT"$N��������ǰ�죬��ֻ����ϸ��������������覴ã����������ص�����֮����\n\n\n" NOR, me, target); 
        if (userp(target)) base=(int)me->query("combat_exp");
                else base=(int)me->query("combat_exp")*per/10;
        
        if( random(target->query("combat_exp")) > base ) {
                message_vision(HIY"$N�ܿ�$n��Ŀ�⣬����бն"+HIY"$n���ţ�\n"NOR, target, me);
                me->set("timer/mihunshu",time());
                return 1;
        }
        message_vision(HIM"һʱ֮�䣬$N"+HIM"����һ�������ѽ���Ϣ���۹����ؿ���$n"+HIM"��������ָ������ǰ��\n\n"NOR,target,me);
   message_vision(RED"$N"+RED"��ͷ����̰��ʹ�����ĺ�������Ѫ����\n\n"NOR,target);
        target->receive_damage("sen", skill*per/15+2*random(skill));
        target->receive_damage("kee", skill*per/20+2*random(skill));
        target->set_temp("last_damage_from",me);
        COMBAT_D->report_status(target);
        COMBAT_D->win_lose_check(me,target,1);
        if (!target->is_busy()) target->start_busy(1);
        me->set("timer/mihunshu",time());
        return 1;
}      
