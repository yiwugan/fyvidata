#include <ansi.h>
inherit SSERVER;
void remove_effect(object me,int amount);
int perform(object me, object target)
{
        int skill; 
                if (target==me) return notify_fail("��������Ϭ��ֻ�ܶԶ���ʹ�á�\n");
                if (!target) target=offensive_target(me);
                if (!target||!target->is_character()||!me->is_fighting(target))
                        return notify_fail("��������Ϭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
                skill=me->query_skill("lingxi-zhi",1);
                if (skill<150)
                        return notify_fail("�����Ϭһָ���������������ܳ���������Ϭ����\n");
                if (me->query_temp("xinyoulingxi"))
                        return notify_fail("���Ѿ���ʩչ��������Ϭ���ˡ�\n");
                
        tell_object(me,HIR"����Ժ��л�ȻһƬ�������Է�һ��һ���޲��������С�\n"NOR);
                me->set_temp("xinyoulingxi", 1); 
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), 10); 
        me->start_busy(2); 
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/defense", - amount); 
        tell_object(me, "�㡰������Ϭ�ġ���Ч�Ѿ���ȥ�ˡ�\n");
}
  
