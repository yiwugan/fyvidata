 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 40 )
                return notify_fail("�������������\n"); 
		write( HIW "���������ľ�������ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + 
HIW"�������ľ�����������֣��Ƽ�͸������������������" + me->name()+ HIW"ȫ��\n" NOR, environment(me), me); 
        me->receive_curing("kee", 20 + (int)me->query_skill("xuanxinjue",1)*2);
        me->add("force", -40);
        me->set("force_factor", 0); 
        return 1;
}
      
