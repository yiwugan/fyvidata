 // mindheal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( !target )
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n"); 
        if( me->is_fighting() || target->is_fighting())
        return notify_fail("ս�����޷����á������ա����ˣ�\n"); 
        if( (int)me->query("force")< 600 )
                return notify_fail("�������������\n");
        
        if (target!=me)
                message_vision(
        HIY "$N�������أ����ƽ���$n��ͷ����������������$n����....\n"
        "Ƭ��֮��$n��ɫһ�����ؿ�ů��������������յ��գ�����һ�����������������ˡ�\n" NOR,
        me, target );
        else 
                message_vision(
        HIY "$N�������أ�һ�ָ��������ת��....\n"
        "Ƭ��֮��$N��ɫһ�����ؿ�ů��������������յ��գ�����һ�����������������ˡ�\n" NOR,
        me); 
        target->receive_curing("sen", 5 + (int)me->query_skill("force"));
        me->add("force", -150);
        me->set("force_factor", 0); 
        return 1;
}  
