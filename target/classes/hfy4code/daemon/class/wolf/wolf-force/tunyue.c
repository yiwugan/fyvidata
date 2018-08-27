 // tunyue.c
#include <ansi.h> 
int exert(object me, object target)
{
        int skill, extra;
        
        skill=me->query_skill("wolf-force",1);
        extra= me->query_skill("summonwolf",1);
    
        if (me->query("class")!="wolfmount")
                return notify_fail("ֻ����ɽ���Ӳ���ʹ�á��������¡���\n");             
        
        if (extra<130)  return notify_fail("��Ļ���֮���������\n");
        if (skill<130)  return notify_fail("��������ķ��������\n"); 
        if(me->query_temp("wolfbuff/tunyue")+240>time())
                return notify_fail("���������¡���������ʩչ����\n");
        if( (int)me->query("force")< 100 )
                return notify_fail("�������������\n"); 
        if( me->is_fighting())  return notify_fail(HIR "ս���в���ʹ�á��������¡���\n"NOR);
        if( !target )   return notify_fail("��ġ��������¡�Ҫ������һͷ�����ϣ�\n");
        if( target->query("id") != "wolf" )
                return notify_fail(target->query("name")+"�����ǣ�����ʹ�á��������¡���\n");
        if( target->query("no_wolf_force") )
        	return notify_fail("����������������ʹ�á��������¡���\n");
        if( me != target->query("possessed"))
                return notify_fail("���������¡�ֻ���������Լ��ٻ��������ϡ�\n");
        if (target->query("wolfbuff"))
                return notify_fail("���Ѿ�����ͷ�������¹������ķ��ˡ�\n");
        
        if( target->query_temp("is_unconcious")) target->revive();
        
        message_vision(
                HIB "$N����һ���������ƴ���$n"HIB"���ģ�ɲʱ�䣬�ƺ�������$n"HIB"��ͨ....\n\n$n" 
                HIG"˫������ӨӨ���̹⣬���˶����壬����һ����������ĳ�����\n" NOR,
                me, target ); 
        target->start_call_out( (: call_other, __FILE__, "remove_tunyue",target :),
                                skill);                          
        target->set("max_kee",me->query("max_kee")*extra/20);
        target->set("eff_kee",target->query("max_kee"));
        target->set("kee",target->query("max_kee"));
        target->set("str",1);
        target->set("wolfbuff",1);
   me->set_temp("wolfbuff/tunyue",time());
        me->add("force",-100);
        me->start_busy(2);
        return 1;
} 
void remove_tunyue(object wolf)
{
    wolf->delete("wolfbuff");
    message_vision(HIG "\n\n$N"HIG"��������˼��£�����һ��������ʧ�ˡ�\n", wolf);
    wolf->die();
}   
