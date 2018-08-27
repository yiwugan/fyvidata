#include <ansi.h>
#include <command.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int lvl;
        object *enemy,*enemy_here;
        
        if( !target ) target = me;
        if( target != me)
                return notify_fail("�۳�����ֻ�ܶ��Լ�ʹ�á�\n");
        
        if (me->query("force")<50)
                return notify_fail("�������������\n");
        
        enemy=me->query_enemy();
        if (enemy)      
                enemy_here=filter_array(enemy,(: environment($1)==environment($2) :),me);
        
        if (!enemy_here || !sizeof(enemy_here))
                return notify_fail("�۳�����ֻ����ս����ʹ�á�\n"); 
        if(!me->is_fighting() ) 
                return notify_fail("�۳�����ֻ����ս����ʹ�á�\n");
                        
        msg = HIY "��ʮ���ƣ���Ϊ�ϲߣ�$N���һ�У�����������������ͼ�ܿ����˵Ĺ��ơ�������\n" NOR;
        lvl = (int)me->query_skill("move");
        me->add_temp("apply/move",lvl*10);
        message_vision(msg, me);
        GO_CMD->do_flee(me);
        me->add("force",-50);
        me->add_temp("apply/move",-lvl*10);
        return 1;
}        
