 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
        notify_fail("��ֻ�ܽ��������ѩ�������Լ������ϡ�\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("stepup") ) return 
        notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
        skill = me->query_skill("notracesnow", 1);
        if ((string)me->query("class") != "taoist" && (string)me->query("class")!="bonze")
                skill=skill/2;
        if(skill < 30) return notify_fail("���̤ѩ�޺�̫���ˣ�\n");
         me->add("force", -100);
        message_vision( HIR
"$N�й����������ξ�Ȼ��������������е�ѩ����\n" NOR, me);
        me->add_temp("apply/dodge", skill);
        me->set_temp("stepup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/2);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("stepup");
        tell_object(me, "��ģ������ѩ��ʩչ��ϣ������ȶ���������\n");
}
  
