 //mimicat@fy4
#include <ansi.h> 
int cast(object me, object target)
{
        int extra;
        
        if(me->query("class")!="lama")
                return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�����ԡ�\n");
        
        extra=me->query_skill("kwan-yin-spells",1);
                        
        if(extra<60)
                return notify_fail("�������������ĵȼ������ߡ�\n");
                
        if(target&& me!=target)
                return notify_fail("������Է���ֻ�������Լ����ϡ�\n"); 
        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ���������\n");
        
        if (me->query_temp("shield_force"))
                return notify_fail("���Ѿ����˷�֮���ˡ�\n");    
        message_vision(
        HIW "$N���ְ�����ǰ����ָ΢����Ĵָ������ָ�࣬������ָչ�����������ţ���������ȡ� \n"
        CYN "$N�������½�������һȦʥ��Ĺ⻪�������������ӡ�\n"NOR     ,
                        me, target ); 
        me->add("mana", -100);
        me->start_busy(2);
        me->set_temp("shield_force/type","mana");
        me->set_temp("shield_force/ratio",100);
        me->set_temp("shield_force/msg",
                CYN"$n���ϵĹ⻪������$N�Ĺ��ơ�\n"NOR);
        extra=extra+random(extra);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/3);     
        // 60/3 =20 sec .. too powerful
        return 1;
}  
void remove_effect(object me)
{
        me->delete_temp("shield_force");
        message_vision(HIW"$N���ϵĹ⻪������ʧ�ˡ�\n"NOR,me);
}       
