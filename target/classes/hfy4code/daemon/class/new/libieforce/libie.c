#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me,object target,int amount)
{
        object *ob;
        int i, extra,level; 
        
        extra = me->query_skill("libieforce");
        level = me->query_skill("libieforce");
        if(me->query("class")!="swordsuper"&& userp(me))
                return notify_fail("ֻ�н����״����Ӳſ���ʹ��"+MAG"�����"NOR+"��\n"); 
        if(extra<100)
        	return notify_fail("�������ķ�������������\n");
        if(me->query_temp("libieforce_libie"))
                return notify_fail("���Ѿ���ʩչ"+MAG"�����"NOR+"�ˡ�\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
      
        me->add("force", -600);
        
        message_vision(WHT"$N������һ��������������ڹ��ķ�����������Χ����$N����Χ......\n"NOR,me);
        if (level>200) level = 200;
        me->set_temp("libieforce_busy",level/50);
        extra= extra+random(extra);
        me->add_temp("libieforce_libie",extra);
        call_out("remove_effect",extra/5,me,extra);
        return 1;
} 
int remove_effect(object me,int extra)
{
        if(!me) return 0;
        me->delete_temp("libieforce_libie");
        me->delete_temp("libieforce_busy");
        tell_object(me,"��"+MAG"����ķ�"NOR+"��Ч���Ѿ���ʧ�ˡ�\n");
        return 1;
}
