 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 40 )
                return notify_fail("�������������\n"); 
        write( HIW "�����𡺰�˪��������ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + 
"���𡺰�˪�����������Ϸ������Ʒ�����ԣ�������һ�亮÷��\nһ�㵭���İ�����ָ�Ƽ�͸����" 
+ me->name()+ "�����˿�ʼ�������ϡ�\n" NOR, 
                environment(me), me); 
        me->receive_curing("kee", 20 + (int)me->query_skill("hanmei-force",1));
        me->add("force", -40);
        me->set("force_factor", 0); 
        return 1;
}
      
