 // powerfade.c
#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
        int skill,num; 
        if( target != me ) 
                return notify_fail("��ֻ���ô�Ѫ��ѹ���Լ���ɱ����\n");
        if( (int)me->query("force") < 100 )     
                return notify_fail("�������������\n");
        if( (int)me->query("bellicosity") <= 0 )
                return notify_fail("�����ں���ɱ����\n"); 
        skill = me->query_skill("doomforce",1);
        num = 100+skill;
        me->add("bellicosity", -num );
        me->add("force", -100);
        me->receive_damage("sen", 100); 
        message_vision( HIC "$N΢һ��������Ѫ�񹦣�������������ʼ�����Լ���ɱ��������\n" NOR, me); 
        me->start_busy(2);
        return 1;
}       
