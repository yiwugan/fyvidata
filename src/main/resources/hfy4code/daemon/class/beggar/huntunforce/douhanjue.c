 // powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill, add; 
        if(me->query("class")!="beggar")
                return notify_fail("ֻ��ؤ����ӲŻᶷ������\n");
        skill = me->query_skill("huntunforce", 1);
        if(skill < 50) return notify_fail("��Ļ��繦̫���ˣ�\n");
        if( target != me ) return 
                notify_fail("��ֻ�������Լ������ԡ�\n");
        if( (int)me->query("force") < 100 )     
                return notify_fail("�������������\n");
        if( (int)me->query_temp("timer/flex") ) 
                return notify_fail("��������Ѿ��õ������ˡ�\n");
        me->add("force", -100);
        message_vision(
                HIR 
"$N��������˼���������������������������ƺ��־����˺࣮ܶ����\n" NOR, me);
       
        target->add_temp("apply/flexibility",skill/3);
        target->add_temp("apply/armor",skill);
        me->set_temp("timer/flex", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/3 :), skill);
        if( me->is_fighting() ) me->start_busy(3); 
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/flexibility", - amount);
        me->add_temp("apply/armor",-me->query_skill("huntunforce",1));
        me->delete_temp("timer/flex");
        tell_object(me, "��ġ���������������ϣ��������ջص��\n");
}
      
