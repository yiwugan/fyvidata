 //mimicat@fy4
#include <ansi.h> 
int cast(object me, object target)
{
        int bonus;
        
        if(me->query("class")!="lama")
                return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�����ԡ�\n"); 
        if( !target)
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
        
        if( !living(target) )
                return notify_fail(target->name() + "�Ѿ��޷�������ĺ����ˡ�\n");
                
        if( (int)me->query("mana") < 500 )
                return notify_fail("��ķ���������\n"); 
        if (target==me) {
                message_vision(
                YEL "$N˫���������裬£����ǰ����������ȵ������\n"
                MAG "���Ƶ�������$N˫�Ƽ�ӿ����������$Nͷ����Ȼ��������ʧ�� \n\n" 
                WHT "����ɢȥ��$N��ͷ�Ǻ�ˮ�����ƽ������ϡ� \n"NOR,
                        me); 
        } else
                message_vision(
                YEL "$N˫���������裬£����ǰ����������ȵ������\n"
                MAG "���Ƶ�������$N˫�Ƽ�ӿ����������$nͷ����Ȼ��������ʧ�� \n\n" 
                WHT "����ɢȥ��$N��ͷ�Ǻ�ˮ��$n�����ƽ������ϡ� \n"NOR,
                        me, target );  
        target->receive_curing("kee", 10 + (int)me->query_skill("spells")*8);
        target->receive_curing("sen", 10 + (int)me->query_skill("spells")*5);
        target->receive_curing("gin", 10 + (int)me->query_skill("spells")*5);
        
        bonus = (me->query("combat_exp")-4000000)/15000;
        if (bonus<0) bonus=0;
        if (bonus>200) bonus = 200;
        
        me->add("mana", bonus-500);
        me->set("mana_factor", 0);
        me->start_busy(2);
        return 1;
}    
