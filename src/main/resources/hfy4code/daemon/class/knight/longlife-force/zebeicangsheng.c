#include <ansi.h>
inherit F_CLEAN_UP; 
void remove_effect(object me, int amount); 
int exert(object me,object target,int amount)
{
        int extra, num, mun; 
        if(me->query("class")!="knight")
                return notify_fail("ֻ�п���ֵ��Ӳ��ܹ����Ե������������С�\n"); 
        if(me->query_temp("resup"))
                return notify_fail("���Ѿ������á��󱻲������ˡ�\n");

		extra = me->query_skill("longlife-force",1);

		if(extra < 150) 
				return notify_fail("��Բ���������û�������\n");
		if((int)me->query_skill("herb") < 150) 
				return notify_fail("���ҩ�������ߣ�\n");
        
        if( (int)me->query("force") < 300 )
                return notify_fail("�������������\n");
      
        me->add("force", -300);
		num = (int)extra / 20;
        //mun = me->query("resistance/kee");

        message_vision(HIW"$N���������֮���衪�����󱻲�������$N�о����Լ�����������ǿ�ˣ�\n"NOR,me);
        
        me->set_temp("resistance/kee", num);
        me->set_temp("resistance/sen", num);
        me->set_temp("resistance/gin", num);
		me->set_temp("resup", 1); 
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
                         num :), (int)extra/4); 
		if( me->is_fighting()) me->start_busy(3); 
        return 1;
} 
void remove_effect(object me,int amount)
{
        me->delete_temp("resistance/kee");
        me->delete_temp("resistance/sen");
        me->delete_temp("resistance/gin");
		me->delete_temp("resup");
        tell_object(me,"��ġ��󱻲�����������ϡ�\n");
}
