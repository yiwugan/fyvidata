#include <ansi.h>
#include <combat.h> 
inherit SSERVER;
void remove_effect_yuanyue(object me);
int perform(object me, object target)
{
		object weapon;
        int extra, agi,str,cor,kar,exp,tarexp; 
        int n;
        
        extra = me->query_skill("moon-blade",1);
        if (me->query("class")!="bandit") extra = extra/5;
        if((int) extra < 150)
                return notify_fail("���Բ��ħ�����������������ܳ������¼�ʱ�Уݡ�\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����¼�ʱ�У�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        message_vision(RED"$N"+NOR RED"���һ����������$n"+NOR RED"��ǰһ������\n"NOR,me,target);
        weapon=me->query_temp("weapon"); 
		agi = me->query("agi");
		str = me->query("str");
		cor = me->query("cor");
		kar = me->query("kar");
		exp = me->query("combat_exp");
		if (exp > 100000000) exp = 100000000;
		if (me->query("moonblade")== 5) exp = exp*5;
		tarexp = target->query("combat_exp");
		
		n=9; 
		
		if(me->query("time/yuanyue")+193>=time()){
			n=3;
			tell_object(me,HIY"���ʹ�ã����¼�ʱ�Уݲ��ã�ͻȻ��������ħ��̫���޷��������գ�\n"NOR);
		}
		else {
			me->set("time/yuanyue",time());
			n=9;
			call_out("remove_effect_yuanyue",210,me);
		}
		
        if (weapon->query("for_modao"))
                if( ( random(extra*extra)+ exp*n+random(exp/3) )*n/3>tarexp*(9/n)+random(tarexp/9) && !target->query("NODIE"))
                {
						message_vision(WHT"\n\n��Ȼ$n"+NOR WHT"����û�п���������ǿ��Ըо���������"+BLINK HIW"$N"+BLINK HIW"��Ȼ������\n"NOR, me, target);
                        me->set_temp("kill_other",1);
                        me->start_busy(2);
                        target->set_temp("last_damage_from",me);
//                        weapon=me->query_temp("weapon");
                        target->remove_killer(me);
                        me->remove_killer(target);
//                        target->apply_condition("moon-blade",1);
//			me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), 3+random(5));
			message_vision(HIC "\n$N"+HIC"��Ȼ�ɶ������Ϊ��Ƭ�������ߵ�����ȥ����\n" NOR , target);
			target->die(); 
			me->delete_temp("kill_other"); 
			me->add("bellicosity",9); 
                }
                else
                {
                message_vision(YEL"��$n"+NOR YEL"�͵�һ������������$N"+NOR YEL"�����ε�һ�У�\n\n"NOR, me, target);
                if (me->query_busy()<3) me->start_busy(3);
                } 
		else
        {       
                me->add_temp("apply/damage",extra*2);
                me->add_temp("apply/attack",extra*5);
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
                me->add_temp("apply/damage",-extra*2);
				me->add_temp("apply/attack",-extra*5);
                if (me->query_busy()<3) me->start_busy(3);
        }
        return 1;
} 

void remove_effect_yuanyue(object me)
{
  me->delete("time/yuanyue");
  tell_object(me,HIY"�����ڴ�Բ�¼�ʱ�е�ħ���������˹�����\n"NOR);
  	
	
}
void kill_him(object me, object target)
{
        string msg; 
        message_vision(HIC "\n$N"+HIC"��Ȼ�ɶ������Ϊ��Ƭ�������ߵ�����ȥ����\n" NOR , target);
//        target->set_temp("last_damage_from",me);
        target->die(); 
        me->delete_temp("kill_other"); 
        me->add("bellicosity",9); 
        return;
}
