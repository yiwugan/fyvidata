 //by xiaolang
#include <ansi.h>
inherit SSERVER; 
int cast(object me, string arg)
{       
        object room;
        int marktime,extra;
        extra=me->query_skill("kwan-yin-spells",1);
        
        if(me->query("class")!="lama")
                return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�����ԡ�\n");      
        if(extra<120) return notify_fail("��Ĺ����������䲻��������\n");      
        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ���������\n");                
        if (me->is_busy())
                return notify_fail("��������æ��\n");
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ������̫�飡\n");
        if( me->is_ghost())
                return notify_fail("����޷�ʹ������̫�飡\n");
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n");
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n");  
         
        me->add("mana", -50);
        me->start_busy(1);
        message_vision( HIR "$N���˫�ۣ�˫�ֺ�һ���ں���ţ����ݣ�����һ������$N�Ƽ�ɳ���������¡�\n" NOR, me);
        room = environment(me);
        marktime=1500+random((me->query_skill("kwan-yin-spells",1)-80)*100);
        me->set_temp("timemark",base_name(room));
        me->set_temp("timemark_time",time()+marktime);
        return 1;
}   
