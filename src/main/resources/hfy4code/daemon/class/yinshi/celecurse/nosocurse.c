#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int add_agi, bonus;
        int my_exp, your_exp;
        if(me->query("class")!="yinshi")
                return notify_fail("ֻ�е����ȵ��Ӳ����½�ͷ��\n");
        //if( !target ) target = me;
        if((int)me->query_skill("celecurse",1) < 20 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
                ||!target->is_character()
                ||target->is_corpse()
                ||target==me)
                return notify_fail("��Ҫ��˭ʩչ�����ͷ��\n");
        if(target->query("possessed")!= me )
        	      return notify_fail("��ֻ�������Լ���������飡\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ������\n");
                
        me->receive_wound("kee", random(100));
        msg = HIR "$N����ͻȻ����һ˿Ѫ�⣬�漴ͻȻð��һ��Ũ����������ߣ�����\n\n" NOR;
        message_vision(msg, me);
        me->delete_temp("timer/solidghost");
        destruct(target); 
        return 1;
} 
