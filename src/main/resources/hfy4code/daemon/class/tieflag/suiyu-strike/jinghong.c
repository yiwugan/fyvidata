//ximen@sxfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,skill,armor;
        object weapon; 
        skill = me->query_skill("suiyu-strike",1);
        extra = me->query_skill("unarmed") ;
        if (me->query("class")!="tieflag" )
                return notify_fail ("����Ѫ���������ײ���ʹ��"RED"�۾����"NOR"������\n");
        if (me->query("family/master_id")!="master yun" && me->query("combat_exp") < 10000000)
                return notify_fail("ֻ������״����Ӳſ���ʹ��"RED"�����衹"NOR"������\n");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                  return notify_fail(NOR"��"RED"����"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ( skill < 130)
                  return notify_fail("��ģ�����ȭ���ݻ��������죡\n"); 
//        if( (int)me->query("kee") >= (int)me->query("max_kee")*3/4)
//        	      return notify_fail("�����û�㵽Ҫʹ�����еĵز��ɣ�\n");
	if(me->query_skill_mapped("force") == "tiexue-force") extra+=skill;
      if( !me->query_temp("tiexue") )
	{ 
	if( me->query_temp("timer/jinghong") + 8 > time() )
              return notify_fail("���ʹ�����"RED"����"NOR"�ݣ�ȫ���������ң����������ٴ�ʹ�ã�\n");
	}
                    armor = target->query("resistance/kee");
        		  target->delete_temp("last_damage_from");
			        me->add_temp("apply/attack", extra*4);
			        me->add_temp("apply/damage", extra*5);
                  message_vision(YEL "\n$N��Х���𣬻���ɢ���ޱ�ɱ������̤�沽��$n�۽���\n"+NOR, me,target);
			        msg =WHT "$n��$Nɱ�����㣬�ĵ��Ժ�����æƮ���˺󡣡���\n"NOR;
			        msg +=MAG"\n��$N�������Ѹ��Ϸ��˵�$n��˫ȭ����̾����ڷ�����ȭ����ǧ��������ֱ��$nҪ����"NOR;
			        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
			        me->add_temp("apply/attack", -extra*4);
			        me->add_temp("apply/damage", -extra*5);
                          if((int)me->query("kee") >= (int)me->query("max_kee")*2/3)
                          me->set_temp("timer/jinghong",time());
                    if( target->query_temp("last_damage_from")  && armor > 0 )
                   {
		            target->set("resistance/kee",0);
                    message_vision(RED"\n$N��ȭ��ֱ����$n���澭������$n�����ܵ���������ˣ�\n"NOR,me,target);
		            target->receive_damage("kee", armor*skill*2/3, me);
		            target->set("resistance/kee",armor);
		            target->set_temp("damaged_during_attack", 1);
		            COMBAT_D->report_status(target, 0);
		            COMBAT_D->win_lose_check(me,target,1);
//                    target->start_busy(1);
                   }
		me->start_busy(2);
        return 1;
}      
