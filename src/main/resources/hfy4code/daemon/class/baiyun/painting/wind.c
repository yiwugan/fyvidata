#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target)
{
        int extra;
        if (me->query("class") != "baiyun") 
                return notify_fail("ֻ�а��Ƶ����ӿ���ʹ�á��ƿ���ɢ����\n");
        extra = me->query_skill("painting", 1);
        if(extra < 50) 
                return notify_fail("��Ļ����ķ��������죬�޷�ʹ�ã��ƿ���ɢ�ݡ�\n");
        if (me->is_naked())
                return notify_fail("���Ѿ����������ˣ����������ƿ���ɢ�ݣ����²�̫�ðɡ�\n");
        
        /*if( !me->is_fighting() )
                return notify_fail("���ƿ���ɢ��ֻ����ս����ʹ�á�\n");
          */
        if( !target ) target = offensive_target(me);
        
        if( (int)me->query("force") < 200 )
                return notify_fail("�������������\n"); 
        
        if( me->is_fighting() || !me->query_temp("apply/painting") ) message_vision(HIG"$N���𻭵��ķ����´�ƮƮ���Ƶ����������ֻ����Χ������ʱ���ƿ���ɢ�������泩��\n"NOR,me);
        else  return notify_fail("����������ʹ�ã��ƿ���ɢ�ݡ�\n");
        me->add("force", -50);
        me->delete_temp("till_death/lockup");
        if (!me->query_temp("apply/painting"))
                me->set_temp("apply/painting", extra);
        call_out("remove_painting",5 + extra/10, me);
        me->start_busy(1);
        return 1;
}  
void remove_painting(object me)
{
    me->delete_temp("apply/painting");
    tell_object(me, "�������������ɬ�����ƿ���ɢ�ݵĹ�Ч��ʧ�ˡ�\n");
}
 
