 // modified from tie
// -by foxgirl@fengyun.com 
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
    int skill;
    int duration;
    
    if (me->query("class") != "huashan") return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á��������ϡ���\n");
    if(!target) target=me;
    else if( target != me )
        return notify_fail("��ֻ�ܽ��۱������ϣ������Լ������ϡ�\n");
    if( (string)me->query("gender") != "Ů��" )
        return notify_fail("��һ�������˾�Ȼѧ��������ŤŤ����Ĺ���Ҳ����˼�ã���\n");
    if( (int)me->query("force") < 100 )
        return notify_fail("�������������\n");
    if( (int)me->query_temp("daoqian") )
        return notify_fail("���Ѿ���ʩչ�۱������ϣ��ˡ�\n");
    skill = me->query_skill("spring-water",1);
    if(skill < 50) 
        return notify_fail("��Ĵ�ˮ����̫���ˣ�\n");
    skill = random(skill/4)+skill/2;
    me->add("force", -100);
    message_vision( HIY
"$N��ü���ף�����۱������ϣݣ����������紺ˮ�������޷��Զ���\n" NOR, me);
    message_vision( HIG
"�ƺ���һ����ϵ�΢�⵭������$N��Χ������\n" NOR, me);
    me->add_temp("apply/iron-cloth", skill);
    me->set_temp("daoqian", 1);
    
    if (me->query("combat_exp")<2500000)        duration = skill;
        else if (me->query("combat_exp")<3500000)       duration=3*skill/2;
                else duration =skill*2;
                
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
                         skill :), duration);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
} 
void remove_effect(object me, int amount)
{
    me->add_temp("apply/iron-cloth", - amount);
    me->delete_temp("daoqian");
    tell_object(me, "��ģ۱������ϣݵĹ�Чɢ���ˡ�\n");
}       
