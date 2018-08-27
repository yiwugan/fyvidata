#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount); 
int exert(object me, object target, int amount)
{
        int skill;
        skill = me->query_skill("manjianghong",1); 

		if(skill < 50) 
                return notify_fail("����������ķ�̫���ˣ�\n");
        if( target != me ) 
                return notify_fail("��ֻ�������Լ���������\n");
        if( (int)me->query("force") < 200 )   
                return  notify_fail("�������������\n");
        if( (int)me->query_temp("manjianghong/cor") ) 
                return  notify_fail("�����ڿ���������\n");
        
        me->add("force", -200);
        message_vision(HIR "$N����Զ����������������̧���ۡ����쳤Х��׳�����ң�\n" NOR, me);
        me->add_temp("apply/courage", skill/5);
        me->set_temp("manjianghong/cor", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill/2);
        me->start_busy(1);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/courage", - amount);
        me->delete_temp("manjianghong/cor");
        tell_object(me, "�������ָ���ƽ����\n");
}
      
