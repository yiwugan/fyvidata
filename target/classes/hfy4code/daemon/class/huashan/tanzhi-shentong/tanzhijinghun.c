 // tanzhijinghun.c
#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target) {
        
        string msg;
        int bonus, damage_bonus, damage, level, lvl;
        
        if(!objectp(target)) target = offensive_target(me);
        
        if (me->query_skill("tanzhi-shentong",1)<80) 
                return notify_fail("��ġ���ָ��ͨ������������\n");
        
        if( !target ) target = offensive_target(me);
        if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
                return notify_fail("����ָ���꡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        }
        
        if (target->query("step_less")==1) 
                return notify_fail(HIW"����������������տ�����ᱻ�˼����Ի�ġ�\n"NOR);
        
        if(target->is_busy()) {
                return notify_fail("�Է��Ѿ����ܶ����ˡ�����\n");
        }
        
        if (me->query("class") != "emei")
        {
               bonus = (int) me->query_skill("tanzhi-shentong",1);
        }else        {    
        	bonus = (int) me->query_skill("tanzhi-shentong",1);
                lvl = (int) me->query_skill("changelaw",1);
        	bonus = bonus+lvl*2;    
        
        }
        msg = HIG"$N"+HIG"��Ӱ��������趯��ָ���ƿ�֮�����Ͳ���Ϯ��"+"$n"+HIG"����ҪѨ��\n"NOR;
        bonus = ((int) random(me->query("combat_exp")/40*bonus)+me->query("combat_exp")/4)/((int) target->query("combat_exp")+1);
        //if (me->query("class") != "huashan") bonus=bonus/2;
        if(bonus >= 1) {
                msg += HIG"$n"+HIG"ֻ���ؿ�����Ѩһ�飬��ʱ�������á�\n" NOR;           
                damage = me->query_skill("throwing")>=420?420:me->query_skill("throwing");
                damage_bonus=me->query("combat_exp")/3000*damage/1000;
                if (damage_bonus>damage*3/2) damage_bonus= damage*3/2; 
                damage = damage+ damage_bonus;
                target->receive_damage("kee", damage, me);
                target->start_busy(3);
                /*if(me->query_skill_mapped("force") != "hanmei-force") {
                        me->start_busy(2);
                }
           else {*/
                        msg += WHT"$N"+WHT"������ת������Ȼ�ټ���ɬ��\n\n"NOR;
                        me->start_busy(1);
                //}       
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
        } else {
                msg += YEL"$n"+YEL"�͵�һ�����������$P"+YEL"��ָ�磡��\n"NOR;
                message_vision(msg, me, target);
                me->start_busy(2);
        }
        return 1;
}   
