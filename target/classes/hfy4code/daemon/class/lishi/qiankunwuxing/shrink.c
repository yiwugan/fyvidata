 // TIE@FY3
#include <ansi.h>
inherit SSERVER;
int conjure(object me, object target)
{
        string msg;
        int lvl,ap,dp;
        if(!me->is_fighting())
        return notify_fail("Ǭ������ֻ������ս����ʩչ��\n"); 
        if( !target )
                target = me;
        else if(me!=target)
                return notify_fail("��Ǭ�����Σ�ֻ���������Լ������ϡ�\n"); 
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("��Ҫ��˭ʩչ���������\n"); 
        if(target->query_temp("in_shrink"))
                return notify_fail("�����ڲ�����Ҫʩչ��Ǭ�����Σ��е�<Ǭ����> \n"); 
        if((int)me->query("atman") < 150 )
                return notify_fail("�������������\n"); 
        if((int)me->query("gin") < 50 )
                return notify_fail("��ľ���û�а취��Ч���У�\n"); 
        me->add("atman", -150);
        me->receive_damage("gin", 50); 
        if( random(me->query("max_atman")) < 30 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        }
        lvl = (int)me->query_skill("magic") /3;
        msg = CYN "\n\n$Nʩչ����Ǭ�����Σ��е�<Ǭ����>��\n\n" ;
        ap = me->query_skill("magic");
        ap = ( ap * ap /100 * ap/30 ) * (int)me->query("gin") ;
        dp = offensive_target(me)->query("combat_exp");
        if( random(ap + dp) > dp ) {
                msg +="$n��ȫ��һ��鴤�������ƺ���С�˼��֣���\n\n";
                seteuid(ROOT_UID); 
                // decrease up to 5 strength, and increase up to 5 agility
                target->set_temp("in_shrink", 1);
                target->add_temp("apply/strength",-lvl / 10);
           target->add_temp("apply/agility",lvl / 10);
                target->start_call_out( (: call_other, __FILE__, "remove_enlarge"
,target, lvl / 10 :),
                random(lvl/2)+lvl/2);
        } else
                msg += "����$N��û�гɹ���\n\n";
        if(me == target) 
        {
        msg = replace_string(msg, "$n","$N");
        message_vision(msg+NOR,me);
        }
        else
        message_vision(msg+NOR, me, target);
        me->start_busy(1); 
        return 1;
} 
void remove_enlarge(object target, int lvl)
{
        target->delete_temp("in_shrink");
        target->add_temp("apply/strength",lvl);
        target->add_temp("apply/agility",-lvl);
        message_vision("$N��ȫ��ǽ�һ���죬����ͻȻ�ߴ��˼��֣���\n",target);
}
