 //silencer@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra,ratio,delay,bonus;
        
        if (me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��������������\n");
        
        if  (me->query("family/master_name")=="������") bonus = 1;
                else bonus=3;
        
        extra=me->query_skill("gouyee",1);
        if(extra<70)
                return notify_fail("������ķ��ĵȼ������ߡ�\n");
        if(target&& me!=target)
                return notify_fail("�������ֻ�������Լ����ϡ�\n");
        if( (int)me->query("force") < 300 )
                return notify_fail("�������������\n");
        if(me->query_temp("shield_force"))
                return notify_fail("���Ѿ����˹����ˣ���\n");
        
        delay = 4-extra/50;
        ratio = extra * bonus;
        me->start_busy(3);
        me->add("force", -300);
        message_vision(MAG"$N���˷�������ɫ������ϡ���������\n"NOR,me);
        me->start_call_out( (: call_other, __FILE__, "take_effect", me, ratio :), delay);
        extra=extra+random(extra);
//      me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra);
        call_out("remove_effect",extra,me);
        return 1;
} 
void take_effect (object me, int ratio) 
{
        message_vision(MAG"����Խ��ԽŨ��������$N��Χ��\n"NOR,me);
        me->set_temp("till_death/shield_lock",1);
        me->set_temp("shield_force/type","mana");
        me->set_temp("shield_force/ratio",ratio);
        me->set_temp("shield_force/msg",
           MAG"$N��ʽ����$n��ǰ����֮�⣬����ţ�뺣,��ʧ�������С�\n"NOR);
}        
void stop_effect(object me)
{
        remove_call_out("remove_effect");
} 
void remove_effect(object me)
{
        me->delete_temp("shield_force");
        me->delete_temp("till_death/shield_lock");
        message_vision(HIW"$N���ϵ�����������ʧ�ˡ�\n"NOR,me);
}       
