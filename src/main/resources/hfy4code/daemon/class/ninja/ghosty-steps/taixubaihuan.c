 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("��̫��ٻã���ֻ��Ů�Ӳ������Ĺ���\n");
        
        skill = me->query_skill("ghosty-steps", 1);
        if(skill < 100) return notify_fail("���̫��ò�̫���ˣ�\n");
        if( target != me ) 
                return  notify_fail("��ֻ�ܽ���̫��ٻã������Լ������ϡ�\n");
        if( (int)me->query("force") < 100 )    
                return notify_fail("�������������\n");
        if( (int)me->query_temp("stepup") ) 
                return notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
         me->add("force", -100);
         message_vision( HIR
"$N��Хһ����ʹ��̫��ò��еģ�̫��ٻãݣ��������к������֣�Ʈ翲�����\n" NOR, me);
         skill=skill/2;
         me->add_temp("apply/dodge", skill*2);
         me->set_temp("stepup", 1);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill*2 :), skill*2);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("stepup");
        tell_object(me, "��ģ�̫��ٻã�ʩչ��ϣ������ȶ���������\n");
}
       
