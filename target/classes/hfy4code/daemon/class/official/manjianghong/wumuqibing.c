 // ice
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target, int amount)
{
        int skill, cor, base, i;
        
        if(me->query("class") != "official")
                return  notify_fail("ֻ�г�͢���ٲ���ָ�ӣ���������ݣ�\n");
		if( me->query("family/master_id") != "master yue" )
                return  notify_fail("ֻ�����ٱ��ĵ��Ӳ���ָ�ӣ���������ݣ�\n");
        if ( me->query_skill("manjianghong",1) < 120 )
			return notify_fail("��ġ��������ķ������������죡\n");
        if (me->query_skill("strategy",1)<200)
                return notify_fail ("���[����]̫���ˡ�\n");
        if((int)me->query("timer/wumu") + 20 > time())
                return notify_fail(YEL"��ող�������������ݡ�\n"NOR);
        if( !me->is_fighting() )
                return notify_fail("ֻ����ս���в�����������ݡ�\n");
        if( (int)me->query("force") < 200 )
                return notify_fail("�������������\n"); 
        enemy = me->query_enemy();         
        if(!sizeof(enemy))
            return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
//        if(target)
//            return notify_fail("�����������Ҫָ��ʹ�ö��󣡣�\n");
            
        skill = me->query_skill("strategy",1);
        
        me->add("force", -200);
        cor = me->query("cor");
		
        message_vision(                
                HIC"\n$N�Ӷ����죬ֻ�� "+HIR"�� "+HIY"�� "+HIB"�� "+HIW"��"+HIC"����ɫ�����Ҿ��������󣬺ƺƵ��������ư��磡\n\n"NOR, me); 
		 
        base=(int)me->query("combat_exp");
//                else base=(int)me->query("combat_exp")*cor/40;
        for (i = 0 ; i< sizeof(enemy); i++) 
        {   
                if( enemy[i]&& enemy[i]->is_character()&& me->is_fighting(enemy[i]) )
                {           
								     if( random(enemy[i]->query("combat_exp")) > base/2 ) 
								     {
									       message_vision(CYN"$N"+NOR CYN"��������һ�ٳ��"+NOR CYN"$n�����ƣ�\n"NOR, enemy[i], me);
								     }
								     else
								     {
								     	   	message_vision(HIR"$N"+HIR"�������У������ɱ�޷�ͻΧ����Ŵ��ң�\n\n"NOR,enemy[i]);
													message_vision(HIR"$N"+HIR"�޷�ͻΧ���۵þ�ƣ������\n\n"NOR,enemy[i]);
													enemy[i]->receive_damage("gin", skill*cor/15+2*random(skill));
													enemy[i]->receive_damage("kee", skill*cor/20+2*random(skill));
													enemy[i]->set_temp("last_damage_from",me);
					                enemy[i]->apply_condition("wumuqibing",random(3)+2);
											    if (!enemy[i]->is_busy()) enemy[i]->start_busy(1);
											    COMBAT_D->win_lose_check(me,enemy[i],1);
								     }
				        }
		    } 
		    me->set("timer/wumu",time());                            
		    if (me->query_busy()<2) me->start_busy(2);
        return 1;
}      