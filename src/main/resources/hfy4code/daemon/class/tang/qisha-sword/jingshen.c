 // tanzhijinghun.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target) {
        
        string msg;
        int bonus, damage_bonus, damage, level, lvl;
        
        if(!objectp(target)) target = offensive_target(me);
        
        if (me->query_skill("qisha-sword",1)<50) 
                return notify_fail("��ġ���ɱ����������������\n");
        
        if( !target ) target = offensive_target(me);
        if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
                return notify_fail("����ɷ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        }
        
        if(target->is_busy()) {
                return notify_fail("�Է��Ѿ����ܶ����ˡ�����\n");
        }
        
        bonus = (int) me->query_skill("qisha-sword",1);
        lvl = (int) me->query_skill("dujing-force",1);
        
        me->add_temp("apply/attack",bonus);
        me->add_temp("apply/damage",bonus+ lvl);
        
        msg = HIW  "\n$N����һ�٣���Ȼʹ������ʧ���Ѿõġ���ɷ���񡹣�һ��������ʽ������\n\n"NOR;
        msg+=HIC"��һʽ��ֱ�����أ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   
        msg = HIC"�ڶ�ʽ������̫�ң�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        msg = HIC "����ʽ����ϮѪ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       
		    msg = HIC  "����ʽ����ɨ�ٳ壡" NOR;
		    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    
        msg = HIC  "����ʽ�����ƶ��ţ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
     
        me->add_temp("apply/attack",-bonus);
        me->add_temp("apply/damage",-bonus-lvl);
 
 msg = HIC"\n$N"+HIC"����עһ��������������ʽ����ʩ��������"+"$n"+HIC"���š���������ҪѨ��\n"NOR;
        bonus = ((int) random(me->query("combat_exp")/40*lvl)+me->query("combat_exp")/4)/((int) target->query("combat_exp")+1);
                if(bonus >= 1) {
                msg += HIG"$n"+HIG"ֻ������Ѩ��һ�飬��ʱ�������á�\n" NOR;           
                damage = me->query_skill("throwing")>=420?420:me->query_skill("throwing");
                damage_bonus=me->query("combat_exp")/3000*damage/1000;
                if (damage_bonus>damage*3/2) damage_bonus= damage*3/2; 
                damage = damage+ damage_bonus;
                target->receive_damage("kee", damage, me);
                target->start_busy(3);
        
                        msg += WHT"$N"+WHT"������ת������Ȼ�ټ���ɬ��\n"NOR;
                        me->start_busy(1);
        
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
        } else {
                msg += YEL"\n$n"+YEL"�͵�һ�����������$P"+YEL"�Ĺ�������\n"NOR;
                message_vision(msg, me, target);
                me->start_busy(3);
                }
 
    me->start_busy(2);

    return 1;
                
}   
