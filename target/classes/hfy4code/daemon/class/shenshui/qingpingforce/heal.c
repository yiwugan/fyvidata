 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if (me->query_skill("qingpingforce",1)<50)
                return notify_fail("�����ƽ�ڹ��ȼ������ߡ�\n"); 
        if( target != me ) return 
                notify_fail("��ֻ�����ڹ����Լ����ˡ�\n");
                
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 100)
                return notify_fail("�������������\n"); 
        write( HIW "������[���ľ�]��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + "����[���ľ�]���������˹����ˣ����ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
                environment(me), me);
        me->receive_curing("kee", 20 + (int)me->query_skill("qingpingforce",1)*2);
        me->receive_curing("gin", 10 + (int)me->query_skill("qingpingforce",1));
        me->receive_curing("sen", 10 + (int)me->query_skill("qingpingforce",1));
        me->add("force", -100);
        me->set("force_factor", 0); 
        return 1;
}    
