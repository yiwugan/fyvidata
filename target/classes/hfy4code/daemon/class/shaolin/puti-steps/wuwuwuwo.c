 // fyteam
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("��ֻ�ܽ����������ң������Լ������ϡ�\n");
    if( (int)me->query("force") < 100 )     
        return notify_fail("�������������\n");
    if( (int)me->query_temp("stepup") ) 
        return notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
        skill = me->query_skill("puti-steps", 1);
        if(skill < 80) {
                return notify_fail("���������ղ���̫���ˣ�\n");
         }
         me->add("force", -100);
     tell_object(me, HIG"����������������ֻ�е���̨һƬ��������ʱ�����������\n"NOR);
     message("vision", HIG"ֻ��" + me->name() + "��ɫׯ�أ���Ϊ������������ţ�����Ҳ��Ȼ�ӿ졣\n"NOR,
                environment(me), me);
                
     if (me->query("class")=="shaolin")  skill=skill;
        else if (me->query("class")=="official")  skill=skill;
             else skill=skill/2;
     me->add_temp("apply/dodge", skill);
        
     me->set_temp("stepup", 1);
     me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
     if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("stepup");
        tell_object(me, "��ģ��������ң�ʩչ��ϣ������ȶ���������\n");
}
  
