 // lifeheal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( !target )
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n"); 
        if( me->is_fighting() || target->is_fighting())
        return notify_fail("ս�����޷����á��̿�ϴ�����ˣ�\n"); 
        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n"); 
        if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
                return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ�����������𵴣�\n");
        if (target!=me)
                message_vision(
        HIW "$N����������ת��˫�ƽ���$n���ģ���������������$n����....\n"
        "Ƭ��֮��$Nͷ��ð��˿˿������$n���һ��������ͷ����̿�һϴ����ɫ������������ˡ�\n" NOR,
                me, target );
        else 
                message_vision(
        HIW "$N����������ת��..\n"
        "Ƭ��֮��$Nͷ��ð��˿˿���������һ��������ͷ����̿�һϴ����ɫ������������ˡ�\n" NOR,
                me); 
        target->receive_curing("kee", 10 + (int)me->query_skill("force"));
        me->add("force", -150);
        me->set("force_factor", 0); 
        return 1;
} 
