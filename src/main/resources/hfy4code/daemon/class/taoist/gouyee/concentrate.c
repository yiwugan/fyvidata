 // concentrate.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        int mana_gain;
        if (me->query_skill("gouyee",1)<30)
                return notify_fail("��Ĺ����ķ�̫��.\n");
        
        if( target && target!=me )
                return notify_fail("���������ֻ�������ָ��Լ��ķ�����\n"); 
//      if( me->is_fighting() )
//                return notify_fail("ս���в��ܾ�������ʹ�������.\n");             
        
        if(amount == -1) amount = 30;
        else if(amount < 30 ) 
                return notify_fail("��������ʮ������\n"); 
        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");
        
        mana_gain =  (10 + (int)me->query_skill("gouyee",1))*amount/100;
        
        if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana") )
                me->set("mana", (int)me->query("max_mana"));
        else
                me->add("mana", mana_gain);
        me->add("force", -amount);
        message_vision(
                HIY "$N��Ŀ�����ù����ķ���������ת��һ�Ρ��������...\n"
                "һ��������$N����ɢ���������$P�Ķ��ģ�Ȼ�Ỻ����ȥ��\n" NOR, 
me); 
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}
     
