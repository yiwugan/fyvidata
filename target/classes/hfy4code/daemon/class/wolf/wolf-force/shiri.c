#include <ansi.h>
string damage_message = ""; 
int exert(object me, object target)
{
        int skill, extra;
        
        skill=me->query_skill("wolf-force",1);
        extra= me->query_skill("summonwolf",1);
    
        if (me->query("class")!="wolfmount")
                return notify_fail("ֻ����ɽ���Ӳ���ʹ�á��������¡���\n");             
        
        if (extra<100)  return notify_fail("��Ļ���֮���������\n");
        if (skill<100)  return notify_fail("��������ķ��������\n");
        
        if(me->query_temp("wolfbuff/shiri")+60>time())
                return notify_fail("���������ա���������ʩչ����\n");
        if( me->is_fighting())
                return notify_fail(HIR "���Լ�����ս���У��޷�����ʹ�����������ա���\n"NOR);
        if( (int)me->query("force")< 100)
                return notify_fail("�������������\n");
        if( target->query("id") != "wolf" )
                return notify_fail(target->query("name")+"�����ǣ�����ʹ�á��������ա���\n"); 
        if( target->query("no_wolf_force") )
        	return notify_fail("����������������ʹ�á��������ա���\n");  
        if( me != target->query("possessed") )
                return notify_fail("��ͷ�ǲ�����ģ���ġ��������ա��޷�������Ѫ����\n");
        if( !target->is_fighting())
                return notify_fail(HIR "��ֻ������ս����ʹ�á��������ա���\n"NOR);
        if( target->query_temp("is_unconcious"))
                return notify_fail( target->name() + "�Ѿ����ԣ��������������ա���\n");
        if (target->query("wolfbuff"))
                return notify_fail("���Ѿ�����ͷ�������¹������ķ��ˡ�\n");
        
        message_vision(
                RED "$N����һ���������ƴ���$n"NOR+RED"���ģ�һƬ�����ĺ���$N����͸��....\n\n"NOR+
                HIR"$n"+HIR"ԭ��Ө�̵�˫�۱�ĵ�Ѫ��ͨ�죬��������Ĺ�â������˻��һ�������Ϊ֮������\n" NOR,
                me, target );
        
        target->start_call_out( (: call_other, __FILE__, "remove_shiri",target:),
                                skill);
                
   target->set("wolfbuff/shiri",1);
        target->set("combat_exp",me->query("combat_exp"));
        target->set_temp("apply/parry",me->query_skill("parry"));
        target->set_temp("apply/attack",me->query_skill("unarmed"));
        target->set("str",me->query("str")+me->query_skill("force")/9); 
        me->add("force",-100);
        me->set_temp("wolfbuff/shiri",time());
        me->start_busy(2);
        return 1;
} 
void remove_shiri(object wolf)
{
        wolf->delete("wolfbuff/shiri");
        message_vision(HIR "\n\n$N"HIR"��������˼��£�����һ�ź�����ʧ�ˡ�\n", wolf);
        wolf->die();
}    
