//ximen@sxfy
//update by xiaolang 2006-9-14
//��Ѫ����Ѫ�Ե����ɣ����ԣ����п��Լ����Լ�����Ѫ������Լ���ս����
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,n,extra; 
        if (me->query("class") != "tieflag") 
                return notify_fail("ֻ����Ѫ�����ŵ��Ӳſ���ʹ�á�"HIR"��Ѫ�յ���"NOR+"����\n");
        if (me->query("family/master_id")!="master yun" )
                return notify_fail("ֻ������״����Ӳſ���ʹ�á�"HIR"��Ѫ�յ���"NOR+"����\n");
        if( target != me ) 
                return notify_fail("��"HIR"��Ѫ�յ���"NOR"��ֻ�������Լ����ϡ�\n"); 
        if( (int)me->query("force") < 300 )
                return notify_fail("�������������\n");
        if( (int)me->query_temp("tiexue") )
                return notify_fail("���Ѿ����˹����ˡ�\n");
//        if( (int)me->query("kee") >= (int)me->query("max_kee")*2/3)
//        	      return notify_fail("�����򲻵��ѣ���ñ������У�\n");
        skill = me->query_skill("tiexue-force", 1);
        if(skill < 100) return notify_fail("�����Ѫ�ķ���Ϊ��û���ң�\n");
        me->add("force", -300);
        message_vision(HIR"$N��Хһ��������ӿ���ޱ߶�־��һ�ɰ�ɫ��"HIW"����"HIR"��������ȫ��\n" NOR, me);
        me->set_temp("tiexue", 1); 
        n = 8 - (int)me->query("kee")*10/(int)me->query("max_kee");
        if(n>=5) n=5;
        if(n<=0) n=1;
        extra = skill*n/5;
        me->add_temp("apply/unarmed", extra);
        me->add_temp("apply/sword", extra);
        me->add_temp("apply/dodge", extra);
        me->add_temp("apply/move", extra);
        me->add_temp("apply/parry", extra);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
extra :), skill/6); 
        return 1;
} 
void remove_effect(object me, int extra)
{
	      if(!objectp(me)) return;//�����ü��ϣ���һobject�����ˣ�������,by xiaolang
        me->delete_temp("apply/unarmed", extra);
        me->delete_temp("apply/sword", extra);
        me->delete_temp("apply/dodge", extra);
        me->delete_temp("apply/move", extra);
        me->delete_temp("apply/parry", extra);
        me->delete_temp("tiexue");
        tell_object(me, "������еĶ�־������ʧ�����ϵĶ���Ҳ��ɢ�����Ρ�\n");
}
       