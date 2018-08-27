// guishenpomie.c by ice@fy4
#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
		object weapon;
        int extra;

        if( target != me ) 
                return notify_fail("�۹��������ֻ�ܶ��Լ�ʹ�á�\n");  
        extra = me->query_skill("demon-force", 1);
        if(extra < 100) 
                return notify_fail("��������ħ�ķ��������죬�޷�ʹ�ã۹�������ݡ�\n");
		if(me->query_skill("blade", 1) < 100)
                return notify_fail("��Ե��������򲻹���\n");
        if(me->is_fighting())
                return notify_fail("ս���в���ʹ�ã۹�������ݣ�\n");    
        if( (int)me->query_temp("bladeup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n"); 
        if( (int)me->query("force") < 100 )
                return notify_fail("�������������\n");
  
        if (userp(me)) me->add("force", -100);
        
        message_vision(HIB "\n$N"+HIB"���������ħ�ķ���ȫ�������������⡣����\n" NOR, me);   
        write(HIY"������Լ��Ե���ʹ�ø��ӵ���Ӧ�֣�\n"NOR); 

        me->add_temp("apply/blade", extra/4);
        me->set_temp("bladeup", 1); 
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, extra/4 :), extra);

        return 1; 
} 

 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/blade", -amount);
        me->delete_temp("bladeup");
        tell_object(me, WHT"��о�˫��һ�������۹�������ݵ�Ч���ƺ���ʧ�ˡ�\n"NOR);
}
