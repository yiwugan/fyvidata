 // soulheal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( !target )
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n"); 
        if( me->is_fighting() || target->is_fighting())
        return notify_fail("ս�����޷����á���絴�����ˣ�\n"); 
        if( (int)me->query("force")< 600 )
                return notify_fail("�������������\n"); 
        if (target!=me)
                message_vision(
        HIG "$N˫��ʮ֧��ָð��˿˿������˲������$nȫ����ʮ������Ѩ....\n"
        "Ƭ��֮��$n�о������棬���ⰻȻ�����һ���������������ö��ˡ�\n" NOR,
                me, target );
        else
                message_vision(
        HIG "$N˫��ʮ֧��ָð��˿˿������˲������������ʮ������Ѩ....\n"
        "Ƭ��֮��$N�о������棬���ⰻȻ�����һ���������������ö��ˡ�\n" NOR,
                me); 
        target->receive_curing("gin", 5 + (int)me->query_skill("force"));
        me->add("force", -150);
        me->set("force_factor", 0); 
        return 1;
}     
