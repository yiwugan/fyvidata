#include <ansi.h>
inherit SSERVER;
void remove_effect(object me);
int perform(object me, object target)
{
        int skill;
//              if (!me->query("marks/�����Ϭ")&& userp(me))
//                      return notify_fail (HIG"�㻹δ�������������Ϭ����\n"NOR);
                
/*              if (target==me) return notify_fail("��������Ϭ��ֻ�ܶԶ���ʹ�á�\n");
                if (!target) target=offensive_target(me);
                if (!target||!target->is_character()||!me->is_fighting(target))
                        return notify_fail("��������Ϭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");*/
        skill=me->query_skill("lingxi-zhi",1);
        if (skill<160 && userp(me))
                return notify_fail("��������Ϭ����Ҫ160����Ϭָ����\n");
        if (me->query_temp("xinyoulingxi"))
                        return notify_fail("���Ѿ���ʩչ��������Ϭ���ˡ�\n");
                
        tell_object(me,HIW"����Ժ��л�ȻһƬ�������Է�һ��һ���޲��������С�\n"NOR);
                me->set_temp("xinyoulingxi", 1); 
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me 
 :), 10); 
        if (me->is_fighting()) me->start_busy(2);
        return 1;
} 
void remove_effect(object me)
{
        me->delete_temp("xinyoulingxi");
        tell_object(me, "�㡰������Ϭ���Ĺ�Ч�Ѿ���ȥ�ˡ�\n");
}
     
