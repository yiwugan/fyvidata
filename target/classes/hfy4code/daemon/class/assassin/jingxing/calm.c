#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount); 
int exert(object me, object target, int amount)
{
        int skill;
        skill = me->query_skill("jingxing",1); 
//      if (me->query("class")!="assassin")
//              return notify_fail ("���ľ�ֻ�н�Ǯ�������ʹ�á�\n"); 
        if(skill < 50) 
                return notify_fail("��ľ����ķ�̫���ˣ�\n");
        if( target != me ) 
                return notify_fail("��ֻ�������Լ��Ķ�����\n");
        if( (int)me->query("force") < 200 )   
                return  notify_fail("�������������\n");
        if( (int)me->query_temp("jingxing/calm") ) 
                return  notify_fail("���Ѿ����˹����ˡ�\n");
        
        me->add("force", -200);
        message_vision(HIR "$N����غ���һ�����������˴��������һ�ľ��磮����\n" NOR, me);
        me->add_temp("apply/composure", skill/10);
        me->set_temp("jingxing/calm", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/10 :), skill*3);
        me->start_busy(1);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/composure", - amount);
        me->delete_temp("jingxing/calm");
        tell_object(me, "��ľ��ľ�������ϣ��������ջص��\n");
}
      
