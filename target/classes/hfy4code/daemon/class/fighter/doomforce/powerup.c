 // powerup.c
#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
        int skill; 
        if( target != me ) 
                return notify_fail("��ֻ���ô�Ѫ�������Լ���ս������\n");
        if( (int)me->query("force") < 100 )    
                return notify_fail("�������������\n");         
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n"); 
        skill = me->query_skill("doomforce",1);
        me->add("bellicosity", 100 + skill);
        me->add("force", -100); 
        if (userp(me) && me->query("class")!="fighter")
        if (skill>=80) 
                skill=80;
                
        message_vision( HIR 
"$N΢һ��������Ѫ�񹦣�ȫ���ǽڷ���һ�󱬶�������죡\n" NOR, me); 
        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/dodge", skill/2);
        me->set_temp("powerup", 1); 
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, WHT"��Ĵ�Ѫ��������ϣ��������ջص��\n"NOR);
}
   