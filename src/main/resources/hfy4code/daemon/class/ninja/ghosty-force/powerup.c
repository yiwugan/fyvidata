#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,amt;
        if( target != me ) return
        notify_fail("��ֻ�����޿����������Լ��ķ�������\n");
        /*if( (string)me->query("gender") != "Ů��" )
                return notify_fail("�޿�������ֻ��Ů�Ӳ��������ڹ���\n");
        */
        if( (int)me->query("force") < 100 )     return
                        notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) return
                        notify_fail("���Ѿ����˹����ˡ�\n");
        skill = me->query_skill("force")/2;
        if (skill>=180) skill=180;
        me->add("force", -100);
        message_vision( HIR"$NĬ���޿������񹦣�ȫ����һ����������Ʈ������\n" NOR, me);
        amt=skill/2;
        me->add_temp("apply/dodge", amt);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,
amt :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "����޿�����������ϣ�ȫ��û��������ƮƮ�ĸо���\n");
}        
