 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( target != me ) 
                return notify_fail("��ֻ�����ڹ����Լ����ˡ�\n"); 
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 100 )
                return notify_fail("�������������\n"); 
        write( HIW "��Ĭ���������������һ����ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + "������ת��һ������³�һ������վ����������ɫ�������ö��ˡ�\n" NOR,
                environment(me), me); 
        me->receive_curing("kee", 20 + (int)me->query_skill("longlife-force",1)*2 );
        me->add("force", -100);
        me->set("force_factor", 0); 
        return 1;
}      
