 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra, i; 
        extra = me->query_skill("jindian-fire",1); 
        if ( extra < 100) return notify_fail("��ģ۽���ݻ𷨣ݻ��������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        enemy=me->query_enemy();
		i = 0;
        me->add_temp("apply/attack", extra);
		me->add_temp("apply/damage", extra/2); 
        msg = HIM  "$N˫�ַ��أ�һ�У����������ݳ�һ��𻨷���$n��" NOR; 
        COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
        if (i==sizeof(enemy)-1) i=0;
			else i++;
        msg = HIM  "$N˫��һ�ϣ�����ڶ������" NOR; 
        COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
        if (i==sizeof(enemy)-1) i=0;
			else i++;
        msg = HIM  "$Nһ��ָ�죬һ����$n"+HIM"һ�ӣ�ֻ��������ɳ�һ���һ�" NOR; 
        if (i==sizeof(enemy)-1) i=0;
        COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra); 
        me->add_temp("apply/damage", -extra/2); 
        me->start_busy(3); 
        return 1; 
}    
