 // fyteam

inherit SSERVER;
#include <ansi.h> 
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)

{
    int skill;
    if( target != me ) 
        return notify_fail("��ֻ�ܽ����ƴ��ۼ��������Լ������ϡ�\n");
	        if(me->query("class")!="swordsman")
                return notify_fail("��ֻ�н���ĵ��Ӳ����ʸ��ã�\n");
    if( (int)me->query("force") < 50 )     
        return notify_fail("�������������\n");
    if( (int)me->query_temp("parryup") ) 
        return notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
        skill = me->query_skill("cloudforce", 1);
        if(skill < 50) {
                return notify_fail("��ĵ����ķ�̫���ˣ�\n");
         }
         me->add("force", -50);
     tell_object(me, HIW"��������������ζ��������۶�����ʱ�о���������������ࡣ\n"NOR);
     message("vision", HIW"��Ȼ֮�䣬" + me->name() + "פ�������������ƺ������ˣ�������ȴ�ָ����ˡ�\n"NOR,
                environment(me), me);
                
     if (me->query("class")=="swordsman")  skill=(skill+random(skill))/2;
        else skill=skill/50;
     me->add_temp("apply/parry", skill);
        
     me->set_temp("parryup", 1);
     me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
     if( me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/parry", - amount);
        me->delete_temp("parryup");
        tell_object(me, "���ƴ��ۼ��������ľ����ƺ�����ղ������ˡ�\n");
}
  
