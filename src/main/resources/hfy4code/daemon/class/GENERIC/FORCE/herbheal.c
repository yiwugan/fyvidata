#include <ansi.h>
int exert(object me, object target, int amount)
{
        int extra;
        
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n"); 
        extra = me->query_skill("herb",1);
        
        if(extra < 100 )
                return notify_fail("���ҩ�����������\n"); 
        if(me->query("force")<500)
                return notify_fail("�������������\n");
                
        write( HIG "��ȫ����ɣ���������ʼ�������ھ����л���������\n" NOR);
        
        message("vision",
                HIG + me->name() + 
"����������ҩ���ķ����ˣ�ͷ��ð�����ư��������ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" 
NOR,
                environment(me), me); 
        me->receive_curing("gin",200+(extra-100)*2);
        me->receive_curing("sen",200+(extra-100)*2);
        me->receive_curing("kee", 2000);
        
        me->add("force", -500);
        me->set("force_factor", 0);
        me->start_busy(2);
        
        return 1;
}
  
