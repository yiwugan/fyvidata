//ice@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra;
        
        if(me->query("class")!="mei")
                return notify_fail("ֻ���ɹ��ֵ�ʥŮ�����������İ������\n");
        extra=me->query_skill("xuanxinjue",1);
        if(extra<90)
                return notify_fail("�����İ�����ĵȼ������ߡ�\n");
        if( me->is_fighting() )
                return notify_fail("ս�����˹���Ѫ������ɱ��\n"); 
        if(target&& me!=target)
                return notify_fail("������Ѫָ��ֻ�������Լ����ϡ�\n");
        if( (int)me->query("kee") <= extra*2 )
                return notify_fail("�����Ѫ������\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("�������������\n");
        if(me->query_temp("xuanxinaomiao"))
                return notify_fail("���Ѿ����˹����ˣ���\n");

        me->add("force", -100);
		me->receive_damage("kee", extra*3/2);
        message_vision(HIR"\n$N"HIR"˫ϥ��أ��������죬һ����Ѫ����������ָ������...\n\n"NOR, me);
        extra=extra+random(extra);
		me->set_temp("xuanxinaomiao",1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/3);
        return 1;
}

void remove_effect(object me)
{
		me->delete_temp("xuanxinaomiao");
        tell_object(me, HIR"��ָ���Ѫ����ʧ�ˡ�\n"NOR);
}
