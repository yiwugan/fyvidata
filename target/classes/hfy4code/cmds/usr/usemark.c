#include <ansi.h>
inherit SSERVER; 
int main(object me, string arg)
{
        string roomname;
        object room;
        int skill,atman;
        if((int) me->query("nofly") == 1 ||me->query_temp("nofly") == 1 )
	  //  if( me->query_temp("nofly") )
                return notify_fail("����Ҫ�����������������ܣ�\n");
		if( me->query("class") == "wudang" ) 
				return notify_fail("�䵱������ʹ��setmark1��setmark2���\n");
        if( (skill=me->query_skill("incarnation",1)) < 160 )
                return notify_fail("��Ҫ������������������ʹ��ʱ��ת����\n");
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ���ɷ���\n");
        if( (atman=me->query("atman")) < 50 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 50 )
                return notify_fail("��ľ�������\n");
        if (me->is_busy())
                return notify_fail("��������æ��\n");
        if( me->is_ghost())
                return notify_fail("����޷�ʹ���ɷ���\n");     
        if( !(roomname=me->query_temp("timespacemark")))
                return notify_fail("��û���趨���ꡣ\n");
        if( time()>me->query_temp("timespacemark_time"))
                return notify_fail("���趨�ĵ����Ѿ�ʧЧ�ˡ�\n");
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n");
        if(environment(me)->query("no_death_penalty") || environment(me)->query("no_fly"))
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n");
        
        me->add("atman", -50);
        me->receive_damage("gin", 50);
        if( random(atman/5+skill*2) <100)      {
                 message_vision( HIC "$N��ָ����������Ĭ���ʲô��Ҳû������\n" NOR, me);
                 return notify_fail("��ģ�ʱ��ת����ʧ���ˡ�\n");      
                }
        message_vision( HIC "$N��ָ����������Ĭ���Ȼ����һ��������ʧ�� ....\n" NOR, me);
        room = load_object(roomname);
        me->move(room);
        message( "vision", HIC "\n��Ȼһ�����̴ӵ���ð����"+me->query("name")+"�������г��֣�\n\n" NOR,
                room, ({ me }) );
        return 1;
} 
