 // ice@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, bonus, i, n, num;
        
        object *enemy;

        if ( me->query("class")!= "huashan")
			return notify_fail("ֻ�л�ɽ���Ӳ���������¾�Ҫ��\n");
        if((int)me->query_skill("dugu-sword",1) < 200)
            return notify_fail("��Ķ��¾Ž�������������\n");      

        enemy = me->query_enemy();

        if(!sizeof(enemy))
            return notify_fail("�۽�ָ��ԭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target)
            return notify_fail("��ָ��ԭ����Ҫָ��ʹ�ö��󣡣�\n");
                
        msg = HBCYN "\n$N"+HBCYN"�Ľ����Ȼ���أ�ȫ������������ѹ���˹�״����Ȼ����һԾ���𣡣���\n\n"NOR;
        message_vision(msg,me);
		num = sizeof(enemy);
		n = num;
		if(n==1) n=2;
		if(n > 3) n = 3;

        extra = me->query_skill("sword") + me->query_skill("move") + n*100;
		bonus = me->query("combat_exp")/1000*extra/8000;
        if((int)me->query_skill("dugu-sword",1) > 250) extra = extra + bonus;
        for(i=0;i<num;i++)
        {
			target = enemy[i];
            if(target->query("combat_exp") < random((int)me->query("combat_exp"))*10+(int)me->query("combat_exp")/3) {
                message_vision(HIW"\n������������������$N"+HIW"��"NOR+RED"��"+HIY"��ָ"NOR+BLU"����"+HIG"��ԭ"+NOR"��"+HIR"��"NOR+YEL"����"+HIB"����"NOR+GRN"����"+NOR"����\n\n"NOR,target);
                target->receive_wound("kee",random(extra/2)+extra/2);
                target->receive_damage("kee",extra+extra/2);
                target->set_temp("last_damage_from",me);
                COMBAT_D->report_status(target);
				COMBAT_D->win_lose_check(me,target,1);
			}
			else message_vision(NOR"\n��$n"+NOR"��׼���ƣ�����ܹ���$N"+NOR"��һ����\n\n"NOR,me,target);

		}

        if (me->query_busy()<n) 
                me->start_busy(n);
        return 1;
}  
