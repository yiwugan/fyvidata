 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        object weapon; 
        extra = me->query_skill("xiruo-blade",1); 
        if ( extra < 50) return notify_fail("��ģ�Ϣ�������ݻ��������죡\n"); 
        if (me->query("class")!="quanli") extra /= 5;
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("�۰˷������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon"); 
        me->add_temp("apply/attack", extra*2); 
//        me->add_temp("apply/damage", extra); 

        msg =  RED "$N"+NOR RED"ʹ��Ϣ�������е����������һʽ�۰˷�����ݣ����е�"+ weapon->name()+NOR RED "�����ؿ���$n"+NOR RED"��˫�ƣ�" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg =  YEL "ֻ��$N"+NOR YEL"����һ����"+ weapon->name()+NOR YEL"����$n"+NOR YEL"����磡" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg =  CYN "$N"+NOR CYN"���һ����"+ weapon->name()+NOR CYN"����$n���Ҽ磡" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", extra*2); 
        me->add_temp("apply/damage", extra); 
        msg = HIB "$N"+HIB"��Хһ�����۹��������֣�ʹ����������߾���----���ֵ��ݣ���$n"+HIB"����ǰ��ȥ��" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -extra*4); 
        me->add_temp("apply/damage", -extra); 
        me->start_busy(3); 
        return 1; 
}       
