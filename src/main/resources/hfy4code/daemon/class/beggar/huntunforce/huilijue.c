 // silencer@fy
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        int ammount; 
        if(me->query("class")!="beggar")
        return notify_fail("ֻ��ؤ����Ӳ�����������İ��\n"); 
        if( target && target!=me )
                return notify_fail("����������ֻ�������Լ����ϡ�\n"); 
        amount = 100;
        
        if( (int)me->query("force") < amount*3 )
                return notify_fail("�������������\n");
                
        me->add("force", -amount*3);
        message_vision(HIY "$N��Ŀ������ת��һ�ܻ����ķ��еġ���������...\n"NOR,me);
        
        if ( (int)me->query_skill("huntunforce",1)<150) 
                {
                if (me->query("food")<100) me->set("food",100);
                message_vision(HIY"$Nֻ����������һ��ů�������пտյĸо���ʱ��Ӱ���١�\n" NOR,me);
                }
        else {
                if (me->query("food")<100) me->set("food",100);
                if (me->query("water")<100) me->set("water",100);
                message_vision(
                        HIY"$Nֻ����������һ��ů�������пտյĸо���ʱ��Ӱ���١�\n" NOR,me);
                message_vision(
                        HIG"$N���ÿڸ�����ĸо�Ҳ��ʧ�ˡ�\n"NOR,me);
             }  
        me->start_busy(3);
        return 1;
}
  
