#include <ansi.h>
inherit SSERVER; 
int main(object me, string arg)
{
        object room;
        int marktime2;
		if( me->query("class") != "wudang" ) 
				return notify_fail("ֻ���䵱���Ӳ���ʹ��������\n");
        if((int) me->query_skill("incarnation",1) < 200)
                return notify_fail("����������������\n");
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ���ɷ���\n");
        if( me->query("atman") < 50 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 100 )
                return notify_fail("��ľ�������\n");
        if (me->is_busy())
                return notify_fail("��������æ��\n");
        if( me->is_ghost())
                return notify_fail("����޷�ʹ���ɷ���\n");     
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n");
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n"); 
        me->add("atman", -50);
        me->receive_damage("gin", 100);
        me->start_busy(1);
        message_vision( MAG "$N�����ķ���˫��һ�ӣ�����һ����ɫ�����������ʧ�� ��������\n" NOR, me);
        room = environment(me);
        marktime2=1500+random((me->query_skill("incarnation",1)-80)*100);
        me->set_temp("timespacemark2",base_name(room));
        me->set_temp("timespacemark_time2",time()+marktime2);
        return 1;
}     
