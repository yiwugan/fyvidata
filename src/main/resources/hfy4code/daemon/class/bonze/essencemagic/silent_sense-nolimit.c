 // void_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
    int lvl;
//      if(me->query("class")!="bonze")
//              return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ�ü�ʶ��ͨ��\n"); 
    if( target ) return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�á�\n");
    
    if (me->is_fighting())
        return notify_fail("��ʶ��ͨ������ս����ʹ�á�\n");
    
    if( me->query("atman") < 100 )
        return notify_fail("�������������\n");
    lvl = (int) me->query_skill("essencemagic",1);
    if(lvl<30) return notify_fail("���ʶ��ͨ����Ϊ�������޷�ʹ�ü�ʶ��ͨ��\n");
    if( me->query("gin") <= 50 )
        return notify_fail("��ľ�������\n");
    me->add("atman", -100);
    me->receive_damage("gin", 50);
    message_vision(HIY "$N��ϥ��������ʼ���ü�ʶ��ͨ��˼�붨 ...\n" NOR, me);
    if( random(me->query_skill("magic"))+50< me->query_skill("magic") && !me->is_fighting())
    {
        tell_object(me,HIW"�����ΧһƬ�ž�����о����岻�ϵ��³���\n"NOR);
        me->move("/d/death/yanluo");
        me->be_ghost(1);
        me->start_busy(5);
        return 1;
    }
    write("����ʲô���鶼û�з�����\n");
    return 1;
}      
