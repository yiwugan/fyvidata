 // fyteam
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("��ֻ�ܽ������������������Լ������ϡ�\n");
    if( (int)me->query("force") < 50 )     
        return notify_fail("�������������\n");
    if( (int)me->query_temp("stepup") ) 
        return notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
        skill = me->query_skill("pyrobat-steps", 1);
        if(skill < 50) {
                return notify_fail("��Ļ�����̫���ˣ�\n");
         }
         me->add("force", -50);
     tell_object(me, HIR"���Ŀ����˫����ͣ���������۲����ӣ������һ�з紵�ݶ�ȴ�����ط��������С�\n"NOR);
     message("vision", HIR"���ڵ�ָ˲��" + me->name() + "˫Ŀһ�գ�ĬȻ������ɵ�����ȴ�������һ����������\n"NOR,
                environment(me), me);
                
     if (me->query("class")=="bat")  skill=skill*2;
        else if (me->query("class")=="yinshi")  skill=skill;
             else skill=skill/5;
     me->add_temp("apply/dodge", skill);
        
     me->set_temp("stepup", 1);
     me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
     if( me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("stepup");
        tell_object(me, "��ģ����������ݹ�Ч��ɢ���������黹ʵ��\n");
}
  
