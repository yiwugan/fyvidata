#include <ansi.h>
inherit SSERVER; 
int conjure(object me, object target)
{       int damage,myexp,yourexp,cpexp,lvl;
        string msg;
    //add qin check here ->
    
    //<-
//    if( me->is_fighting() )
//        return notify_fail("�����񳯷������ս�����ࡣ\n"); 
/*
play ���񳯷play bainiaochaofeng) ��60 lev music��������100�㣬���1���� 
���ܷ���ʹ��) 
CYN���Ღ���ң�����������ƽ���кͣ�����������֮�⣬�����ÿ�������֮�������������� 
������ȸ�񣬻�ֹЪ���ۣ������°��裬ë���ͷף�εΪ��ۡ� 
GRN�̿���һֻ�������������˼��£�����һ����ݶ��������ϣ�����һ�������˿�ȥ�� 
*/
		lvl = me->query_skill("music",1);
		 if(me->query("class") != "baiyun") lvl = lvl/2;
        if(lvl < 100)
                return notify_fail("����ٵ������ߣ�\n");
               
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����񳯷ֻ����ս�������ࡣ\n"); 
        if((int)me->query("gin") <= 50 )
                return notify_fail("��ľ���������\n"); 
        if((int)me->query("atman") < 50 )
                return notify_fail("�������������\n");

		me->receive_damage("gin", 50);
        me->add("atman",-50);
/*        if( random(me->query("max_atman")) < 200 ) {
                write(CYN"��ʧ���ˣ�\n"NOR);
                return 1;
        }*/
        msg = HIC "\n$N"+HIC"�Ღ���ң�����������ƽ���кͣ�����������֮�⣡\n" NOR;
		msg += HIC "�����ÿ�������֮��������������������ȸ�񣬻�ֹЪ���ۣ������°��裬ë���ͷף�εΪ��ۡ�\n\n"NOR;
        message_vision(msg, me);
		if( target->query("big_boss") || me->query_skill("music") < random(target->query_skill("perception")) * 3/2) {
			message_vision(HIR"����$N"+HIR"������λ������ֱ��$n�����ţ�\n"NOR, target,me);
			if(!me->is_busy()) me->start_busy(1);
			return 1;
		}

        damage = me->query_skill("magic")*5;
        damage = damage + random(damage);
         if(me->query("class") != "baiyun") damage= damage/10;
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=myexp/2+ (4+lvl/100)*random(myexp)/2;
		if(yourexp>5000000) yourexp = yourexp*3/2;
			 if(me->query("class") != "baiyun") yourexp = yourexp * 3;
			 	 if(me->query("class") == "baiyun") cpexp = cpexp *2;

        if( target->query_busy() ) {
                message_vision(CYN "���к�Ȼ����һֻ����ݺ�����$N"NOR CYN"���̶�����������ȥ��\n" NOR, target);
				if(random((int)me->query_skill("magic")) > 50) {
                target->receive_damage("sen", damage, me);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
				}
				else message_vision(HIR "����$N"HIR"һ�������ڿ��������㿪����һ����\n" NOR, target);
		} else if (yourexp < cpexp) {
            message_vision(HIY"һ����������������$N"+HIY"ʹ�������˫�����Ų�Ư���������࿪ʼ����Ժ���\n"NOR, target); 
			target->receive_damage("sen", damage/10, me);
            target->start_busy(3+random(lvl/50));
		}
		else {
			message_vision(HIG"����$N"HIG"�Լ�����������֮�У�������ս����\n"NOR, me);
		}			
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
}      