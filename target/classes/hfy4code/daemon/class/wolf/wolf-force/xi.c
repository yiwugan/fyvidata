#include <ansi.h> 
int exert(object me, object target)
{
        int skill, extra;
        int tarforce;
        int myforce;      
        skill=me->query_skill("force",1);
    
        if (me->query("class")!="yihua")
                return notify_fail("ֻ���ƻ������Ӳ���ʹ�á������񹦡���\n");             
        
        if (skill<130)  return notify_fail("��������񹦻��������\n");
        if( (int)me->query("max_force")< 2000 )
                return notify_fail("��������������ʹ�ô��������߻���ħ��\n"); 
        if( me->is_fighting())
        	return notify_fail(HIR "ս���в���ʹ����������ȡ������\n"NOR);
        if( me->query("force")>=6*(int)me->query("max_force") )
                return notify_fail("��ֻ����ȡ��ô�������ˡ�\n");           
        if( !target )
        	return notify_fail("����Ҫ��ȡ˭��������\n");
        if(!living(target))
        	return notify_fail("���ǻ��������������\n");	
        if( target == me)
                return notify_fail("�������񹦡����������Լ����ϡ�\n");
        if (target->query("force")<=0)
                return notify_fail("����û�������ģ���ֵ�����ô��񹦡�\n");                       
        message_vision(
                HIM "$N����һ��������˫���͵ض�׼$n�����д�Ѩ������ȥ����\n\n"NOR,
                me, target ); 
        tarforce=target->query("force");
        myforce=me->query("force");
	tell_object(target, HIR "��پ�ȫ��������ˮ����ѭ�׷�й������\n" NOR);
	tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);
	target->set("force",0);
	me->add("force",tarforce);
	target->start_busy(1);
	message_vision(
			WHT"$N����ȫ�����������һ�㣬̱���ڵء���\n"NOR,
			target);
	target->unconcious();
	me->start_busy(1);
        return 1;
}  
