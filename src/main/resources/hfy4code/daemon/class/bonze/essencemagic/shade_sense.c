 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int conjure(object me, object target)
{
        int lvl,i;
        object env, *inv; 
if(me->query("class")!="bonze" && me->query("class")!="yinshi" )
                return notify_fail("ֻ�еõ���ɮ����������ʿ�ſ���ʹ����ʶ��ͨ��\n");
        
        lvl = (int) me->query_skill("magic");
        if ( lvl <= 200)
                return notify_fail("�㷨�������ߣ�\n");
        
        if( me->query("atman") < 100 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 50 )
                return notify_fail("��ľ�������\n");
        
        if(me->query("env/invisibility"))
                return notify_fail("������ʩչ����ʶ��\n");
        
        me->add("atman", -100);
        me->receive_damage("gin", 50);
        
        message_vision(HIW "$N����������һ�Ű�âէ�����ڣ������˽����黯������\n" NOR, me);
        me->start_call_out( (: call_other, __FILE__, "take_effect", me :), 5);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 20+lvl/10+3*random(lvl/10));
        if( me->is_fighting() ) me->start_busy(3);
        return 1; 
}
void remove_effect(object me)
{
        me->set("env/invisibility", 0);
        message_vision(HIG "$N�����ν��������ֳ�����\n" NOR, me);
        me->move(environment(me));
        me->start_busy(1);
        tell_object(me,YEL"�����ʶʧЧ�ˡ�\n"NOR);
} 
void take_effect (object me)
{
        me->set("env/invisibility", 1);
        tell_object(me,YEL"�����ʶ�ɹ��ˡ�\n"NOR);
        
} 
        
       
