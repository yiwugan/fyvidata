 // �����Ŀ�ɱ��,�ڶ�ʱ���ڴ���ȵ��������,���ǲ���perform.
#include <ansi.h> 
inherit SSERVER;
int conjure(object me, object target)
{
        int lvl,i,extra;
        
        lvl = (int) me->query_skill("magic");
        
//      if (me->query("class")!="ninja")
//              return notify_fail("ֻ�����߲���������.\n");
        
        if ( (int) me->query_skill("ninjitsu",1) <= 100)
                return notify_fail("�����������ߣ�\n");
        
        if( target != me ) 
                return notify_fail("��ֻ�ܽ��ۿ�ɱ�������Լ������ϡ�\n");       
                
        if(me->query_temp("ninjitsu_berserk")) 
                return notify_fail("��������Ѿ�����������޶ȣ��޷����������ˡ�\n");
        
        if( me->query("atman") < 300 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 150 )
                return notify_fail("��ľ�������\n");
    
        me->add("atman", -300);
        me->receive_damage("gin", 150);
        extra=lvl/8;
       if (me->query("class")=="shaolin")  extra = extra *5/2;
         	        
        me->add_temp("apply/strength",extra);
        me->set_temp("ninjitsu_berserk",1);
        me->set_temp("till_death/shield_lock",1);
        message_vision(HIR "$N���һ����������Ҫ�γ�Ѫ��.\n"NOR,me);
        tell_object(me,WHT"    ��ֻ����������������,�޴���й������\n" NOR, me);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,extra:), extra*4);
        if( me->is_fighting() ) me->start_busy(2);
        return 1; 
}
void remove_effect(object me,int extra)
{
        me->add_temp("apply/strength", -extra);
        me->delete_temp("till_death/shield_lock");
        me->delete_temp("ninjitsu_berserk");
        tell_object(me, HIG"������������ƽ������\n"NOR);
}  
