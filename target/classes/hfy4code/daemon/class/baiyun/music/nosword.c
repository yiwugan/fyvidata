#include <ansi.h>
inherit SSERVER; 
int conjure(object me, object target,object weapon)
{       int damage,myexp,yourexp,cpexp,lvl,sword;
        string msg;
	int res_kee,res_gin,res_sen;
	int no_busy,x;
	
	no_busy = 0;  
       if ((me->query("class")!="fighter")&&(me->query("class")!="baiyun"))
                return notify_fail ("���޽��ķ���ֻ�ܽ�����Ӳſ�ʹ�á�\n");

		lvl = me->query_skill("doomsword",1);
		sword = me->query_skill("sword",1);
        if(lvl < 180)
                return notify_fail("��ĺ��촵Ѫ����δ�ܴﵽ���޽����ľ��磡\n");
        if(sword < 401)
                return notify_fail("��ĺ��촵Ѫ����δ�ܴﵽ���޽����ľ��磡\n");
                
        x=(lvl-170)/2;
        if(x==0) x=1;
        if(x>=50) x=50;
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���޽��ķ���ֻ����ս����ʹ�á�\n"); 
        if((int)me->query("gin") < 100 )
                return notify_fail("��ľ���������\n"); 
        if((int)me->query("atman") < 100 )
                return notify_fail("�������������\n");

		me->receive_damage("gin", 100);
        	me->add("atman",-100);
/*        if( random(me->query("max_atman")) < 200 ) {
                write(CYN"��ʧ���ˣ�\n"NOR);
                return 1;
        }*/
        res_kee=target->query("resistance/kee");
        res_gin=target->query("resistance/gin");
        res_sen=target->query("resistance/sen");
        if(target->query("no_busy"))
		no_busy=target->query("no_busy");
        if ( me->query_temp("weapon"))
        {
        	 //return notify_fail ("���޽��ķ���������ֲ���ʹ����\n");
                weapon = me->query_temp("weapon");
                //if(weapon->query("equipped") == "wielded") 
                msg = HIC "\n$N"+HIC"����һ���������������ۼ�ת����ָΪ�������ƴ�����\n" NOR;
		msg += HIW "ֻ�����콣�⡣һ˿˿����˺�ѿ�����ֱ��$nҪ������Ȼ����������ʽ�ġ��޽��ķ�����\n\n"NOR;
        	message_vision(msg, me, target);
                 weapon->unequip();
                 	//return 2;
        }
        else
        {
        msg = HIC "\n$N"+HIC"˫�ֲ�ָΪ����ָ���ֱ����������һ���������������£����ƴ�����\n" NOR;
		msg += HIW "ֻ�����콣�⡣һ˿˿����˺�ѿ�����ֱ��$nҪ������Ȼ����������ʽ�ġ��޽��ķ�����\n\n"NOR;
        message_vision(msg, me, target);
                 	//return 2;
        }
        
		if ( me->query_skill("music",1) < random( (target->query_skill("perception")))/3) {
			message_vision(HIY"����$N������λ���ܹ��������ν�����ֱ��$n�����ţ�\n"NOR, target,me);
			if(!me->is_busy()) me->start_busy(2);
			return 1;
		}

        damage = sword + lvl;
        damage = damage + random(damage);
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=random(myexp/2);
		if(yourexp<10000000) yourexp = yourexp*2/3;
             if (yourexp*2 < myexp) {
             	target->set("resistance/kee",res_kee/x);
             	target->set("resistance/gin",res_gin/x);
             	target->set("resistance/sen",res_sen/x);
             	message_vision(HIR "�����Ľ����ᴩ$N�����壬��â������Ѫ���������ڷ�Բʮ��֮�ڡ�\n" NOR, target);
                     target->receive_damage("kee", damage*4, me);
                     target->receive_damage("gin",damage*2,me);
                     target->receive_damage("sen",damage*2,me);
                     target->set("resistance/kee",res_kee);
                     target->set("resistance/sen",res_sen);
                     target->set("resistance/gin",res_gin);
                     COMBAT_D->report_status(target);
                     COMBAT_D->win_lose_check(me,target,1);
                }
                else
                {        if( target->query_busy()>3) {     //changed by ever,if target busy 1 or busy 0,continue busy
                	target->set("resistance/kee",res_kee/x);
             		target->set("resistance/gin",res_gin/x);
             		target->set("resistance/sen",res_sen/x);
                message_vision(HIR "�����Ľ����ᴩ$N�����壬��â������Ѫ���������ڷ�Բʮ��֮�ڡ�\n" NOR, target);
				if(random((int)me->query_skill("magic")) > 50) {
                target->receive_damage("gin", damage*5, me);
                target->receive_damage("kee", damage*4, me);
                target->receive_damage("sen", damage*4, me);
                target->set("resistance/kee",res_kee);
                target->set("resistance/sen",res_sen);
                target->set("resistance/gin",res_gin);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
				}
				else message_vision(HIY "����$N"HIY"һ�������ڿ������㿪����һ����\n" NOR, target);
		} else if (yourexp > cpexp) {
           //changed by ever,while music is 200,rate is 200-200+random(200)/3>50 = 1/4			
            if ((me->query_skill("music",1)-200+random(me->query_skill("music",1))/3)>50) target->delete("no_busy");
            message_vision(HIG"����ʮ��·����ʮ��·����������$N��ȫ��Ѩ���ϣ�$N��ʱ�������á�\n"NOR, target); 
			target->receive_damage("gin", damage, me);
            target->start_busy(4+random(lvl/40));
            target->set("no_busy",no_busy);
		}
		else {
			message_vision(HIY"����һ���þ���$N��Ϣ���ܿ��ƣ���ǰ¶�����ţ�\n"NOR, me);
		}
	}		
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
}      
