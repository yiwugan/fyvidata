 //mimicat@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra,ratio,delay;
        
        extra=me->query_skill("yijinjing",1);
        if(extra<150)
                return notify_fail("���׽�ĵȼ������ߡ�\n");
                
        if(!me->query_temp("shield_force"))
                return notify_fail("�㲻���˹��С�\n");
        if (me->is_fighting())
        {
                return notify_fail("��ս���в����ջػ����񹦡�\n");
        }
        /*
        if(me->query("class")!="shaolin")
                return notify_fail("ֻ�����ָ�ɮ����ʹ���׽�Ļ����񹦡�\n");*/
        
        if(target&& me!=target)
                return notify_fail("ȡ��������ֻ�������Լ����ϡ�\n");
        call_other(__DIR__"shield.c","stop_effect",me);
        me->start_busy(3);
        me->set("force",0);
        me->delete_temp("shield_force");
    me->delete_temp("till_death/shield_lock");
    message_vision(HIW"$N������һ����,�����ջ�����ߵĻ�����ǽ��\n"NOR,me);
        return 1;
}    
