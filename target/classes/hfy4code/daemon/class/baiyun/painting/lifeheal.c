 // lifeheal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( !target )
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n"); 
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˣ�\n"); 
        if( (int)me->query("force") < 150 )
                return notify_fail("�������������\n"); 
        if (target!=me){
        message_vision(HIC "$N���𻭵��ڹ�������������$n���ģ������ؽ���������$n����....\n\n"NOR,me,target);
        message_vision(HIC"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me,target);
        }       else
        {message_vision(HIY "$N���𻭵��ڹ��������ؽ�������������ת....\n\n"NOR,me);
        message_vision(HIY"���˲��ã�$N�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me);
        }
        target->receive_curing("kee", 10 + (int)me->query_skill("painting",1));
        me->add("force", -50);
        me->set("force_factor", 0); 
        return 1;
}
