 //mimicat@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra,ratio,delay;
        
        if(me->query("class")!="shaolin")
                return notify_fail("ֻ�����ָ�ɮ����ʹ���׽�Ļ����񹦡�\n");
        extra=me->query_skill("yijinjing",1);
        if(extra<100)
                return notify_fail("���׽�ĵȼ������ߡ�\n");
        if(target&& me!=target)
                return notify_fail("������ֻ�������Լ����ϡ�\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("�������������\n");
        if(me->query_temp("ninjitsu_berserk")) 
                return notify_fail("�������׽�����ݡ�\n");
        if(me->query_temp("shield_force"))
                return notify_fail("���Ѿ����˹����ˣ���\n");
        delay = 3-extra/100;
                ratio = extra *5;
                if (me->query("once_xman")==1) ratio = ratio *2;
        me->start_busy(3);
        me->add("force", -500);
        message_vision(YEL"$N����һ���������������ȶ�������������\n"NOR,me);
        me->start_call_out( (: call_other, __FILE__, "take_effect", me, ratio :), delay);
        extra=extra+random(extra);
        //me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra);
        call_out("remove_effect",extra,me);
        return 1;
} 
void take_effect (object me, int ratio) 
{
        message_vision(YEL"�����Ŷ����ƺ���$N��Χ���һΧ��ǽ��\n"NOR,me);
        me->set_temp("till_death/shield_lock",1);
        me->set_temp("shield_force/type","force");
        me->set_temp("shield_force/ratio",ratio);
        me->set_temp("shield_force/msg",
                YEL"$N��ʽ����$n��ǰ����֮�⣬����������һ������֮����ȴ�ּ�Ӳ֮�������ϡ�\n"NOR);
}          
void remove_effect(object me)
{
        me->delete_temp("shield_force");
        me->delete_temp("till_death/shield_lock");
        message_vision(HIW"$N���ϵ���ǽ������ʧ�ˡ�\n"NOR,me);
} 
void stop_effect(object me)
{
        remove_call_out("remove_effect");
} 
