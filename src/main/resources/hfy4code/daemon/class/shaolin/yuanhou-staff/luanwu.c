 // tanzhijinghun.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target) {
        
        string msg;
        int bonus, damage_bonus, damage, level, lvl;
        
        if(!objectp(target)) target = offensive_target(me);
        
        if (me->query_skill("yuanhou-staff",1)<50) 
                return notify_fail("��ġ�Գ�����������������\n");
        
        if( !target ) target = offensive_target(me);
        if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
                return notify_fail("��ȺԳ���衹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        }
        
     /*   if(target->is_busy()) {
                return notify_fail("�Է��Ѿ����ܶ����ˡ�����\n");
        }*/
        
        bonus = (int) me->query_skill("yuanhou-staff",1);
        lvl = (int) me->query_skill("staff",1);
        
                if(me->query("class")!="bonze"&&me->query("class")!="shaolin")
                bonus/=5;   
                if(me->query("class")!="bonze"&&me->query("class")!="shaolin")
                lvl/=10;   
        
        me->add_temp("apply/attack",bonus+lvl);
        me->add_temp("apply/damage",bonus*2+lvl*2);
        
        msg = HIW  "\n$N��߸�Ծ����Ӱ���������������������һ�С�Գ�����衹������\n\n"NOR;
        msg+=HIC"������ͷһ��������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   
        msg = HIC"��ǰ��ӭ��һ��������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        msg = HIC "��������һ�ã�����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       
		    msg = HIC  "�󷽳���̫��Ѩ����һɨ������" NOR;
		    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    
        msg = HIC  "�Ҳ�����������������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
     
        me->add_temp("apply/attack",-bonus-lvl);
        me->add_temp("apply/damage",-bonus*2-lvl*2);
 
     me->start_busy(3);
    return 1;             
}