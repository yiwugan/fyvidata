 // powerfade.c
#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
        int extra; 
        if( target != me ) 
                return notify_fail("��ֻ�ܶ��Լ�ʹ�á�������������\n");
        if( me->is_fighting() )
                return notify_fail("ս���в������á�������������\n"); 

        extra = me->query_skill("wuzheng-force",1);
        if(extra < 100 )
                return notify_fail("��������ķ���򲻹���\n"); 
        if( (int)me->query("force") < 300 )     
                return notify_fail("�������������\n");
		if(me->query("class") != "bat") extra = extra / 10;

        if( (int)me->query("bellicosity") > 0 )
		{
				me->add("bellicosity", -extra-100 );
		}

		message_vision(WHT"$N�߶��ڹ���ֻ�о���������������ɢ��˵�������������\n" NOR, me); 

        me->receive_curing("kee", 6*extra);
        me->receive_curing("sen", 6*extra);
        me->receive_curing("gin", 6*extra);
        me->add("force", -300);
        me->set("force_factor", 0); 
        me->start_busy(2);
        return 1;
}       
