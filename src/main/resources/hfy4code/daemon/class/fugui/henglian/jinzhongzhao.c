 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
                if(!target) target=me;
        if(me->query("class")!="fugui")
                return notify_fail("ֻ�и���ɽׯ���Ӳ���ʹ���������֡��ľ�����\n");
        if(me->query("gender")!="����")
                return notify_fail("�����������Ĺ����㡮�֡�ʲô����\n");     
       if( target != me ) return 
                    notify_fail("��ֻ�ܽ��������֡������Լ������ϡ�\n");
        if( (int)me->query("force") < 200 )     return
                        notify_fail("�������������\n");
        if( (int)me->query_temp("daoqian") ) return 
                        notify_fail("���Ѿ���ʩչ�������֡��ˡ�\n");
        skill = me->query_skill("henglian",1);
        if(skill < 100) return notify_fail("���ʮ��̫��������̫���ˣ�\n");
        skill = random(skill)+skill/2;
        me->add("force", -150);
        message_vision( 
HIY"$N��������ȫ��ǽ�һ�����죬�������κ�Ȼ����һȦ����\n" NOR, me);
        me->add_temp("apply/iron-cloth", skill);
        me->set_temp("daoqian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("daoqian");
        if( me->is_fighting() ) me->start_busy(1);      
        tell_object(me, "��ġ������֡���Чɢ���ˡ�\n");
}
     
