 // silencer@fy
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;
        int gin;
        int kee;
        int sen;
        if(me->query("class")!="bonze")
                return notify_fail("ֻ���˹����µĵ��Ӳ����̶�սʤ����\n");
        
        skill = me->query_skill("lotusforce", 1);
        if(skill < 10) return notify_fail("��������ķ�̫���ˣ�\n");
        
        if( target != me ) 
                return notify_fail("��ֻ�������Լ������ܡ�\n"); 
        if( (int)me->query("force") < 100 )   
                return notify_fail("�������������\n");
        if( (int)me->query_temp("douzhan") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
        
        me->add("force", -100);
        message_vision(HIY"$N���һ������ �� �� �� �� �� �� �� ǰ����ȫ���������Ľ�⣮����\n" NOR, me);
        gin = (int)me->query("gin");
        kee = (int)me->query("kee");
        sen = (int)me->query("sen");
        me->set("gin",gin+gin*skill/500);
        me->set("kee",kee+kee*skill/500);
        me->set("sen",sen+sen*skill/500);
        me->set_temp("douzhan", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        int gin;
        int kee;
        int sen;
        gin = (int)me->query("gin");
        kee = (int)me->query("kee");
        sen = (int)me->query("sen");
        me->set("gin",gin-gin*amount/500>0?gin-gin*amount/500:1);
        me->set("kee",kee-kee*amount/500>0?kee-kee*amount/500:1);
        me->set("sen",sen-sen*amount/500>0?sen-sen*amount/500:1);
        me->delete_temp("douzhan");
        tell_object(me, "��ġ���սʤ����������ϣ��������ջص��\n");
}
       
