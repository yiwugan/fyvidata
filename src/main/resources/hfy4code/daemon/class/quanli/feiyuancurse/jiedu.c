 // recover.c
inherit SSERVER;
#include <ansi.h>
#include <condition.h> 
int perform(object me, object target) 
{ 
        int force, lvl, extra; 
        if( target != me ) return notify_fail("��ֻ�����������Լ����ڶ��رƳ���\n"); 
        force =(int) me->query("force"); 
        if( force < 100) return notify_fail("����������㡣\n"); 
        lvl = me->query_skill("herb",1); 
		extra = me->query_skill("feiyuancurse",1);
        if( lvl < 50) return notify_fail("��ģ�ҩ���ݲ���������������Ϊ�Լ��ⶾ��\n"); 
        if( extra < 50) return notify_fail("��ģ۷�ԩ�������ݲ���������������Ϊ�Լ��ⶾ��\n"); 
 
        me->add("force", -100); 
        message_vision(WHT"$N�˹�������׼���Ѷ��Ƴ����⣮����\n"NOR, me); 
        me->start_busy(1);
        if (random(lvl) < 20) 
        { 
                return notify_fail(YEL"����ʧ���ˡ�\n"NOR); 
        } 
        else 
        { 
        me->clear_condition();   
                write(HIG"��ɹ��رƳ����ڵľ޶���\n"NOR); 
        return 1; 
        } 
} 
     
