 //sfy@fy4
//mod by ice@fy4
#include <ansi.h> 
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill, duration;
        
        if(me->query("class")!="mei")
                return notify_fail("ֻ���ɹ��ֵ�ʥŮ�����������İ������\n");
		skill = me->query_skill("xuanxinjue",1);
		if(skill < 50) 
            return notify_fail("������İ���������ߣ�\n");
		if(!target) target=me;
        else if( target != me )
	       return notify_fail("��ֻ�ܽ������İ���������Լ����ϡ�\n");
	    if( (string)me->query("gender") != "Ů��" )
            return notify_fail("��Ů�Ӳ�����������İ���ݵ����С�\n");
		if( (int)me->query_temp("daoqian") )
            return notify_fail("���Ѿ���ʩչ�����İ�����ˡ�\n");
		if( (int)me->query("force") < 200 )
            return notify_fail("�������������\n");
		skill = random(skill/4)+skill/2;
		me->add("force", -200);
        message_vision(HIW"\n$N"HIW"һ��ʥ�࣬�������������-��-��-��  ��-��-��-�ڡ���\n"NOR,me);
        message_vision(HIY"һ����ɫʥ�⻺���ſ���$N"HIY"���������Ź�â�İڶ��������������У�����\n"NOR,me);
		me->add_temp("apply/iron-cloth", skill);
		me->set_temp("daoqian", 1);
    
		if (me->query("combat_exp")<2500000)        duration = skill;
        else if (me->query("combat_exp")<3500000)       duration=skill*2;
                else duration =skill*5/2;
                
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
                         skill :), duration);
		if( me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void remove_effect(object me,int amount)
{
		me->add_temp("apply/iron-cloth", -amount);
		me->delete_temp("daoqian");
        tell_object(me, HIW"�����ϵ�ʥ�⽥����ʧ�ˡ�\n"NOR);
} 
