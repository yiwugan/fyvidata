 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra,dodge; 
        object weapon; 
        if (me->query("class")!="quanli")
                return notify_fail ("��÷����ȣ�ֻ�в�������ֵܽ��ò���ʹ�á�\n");
        dodge = me->query_skill("stormdance",1); 
        extra = me->query_skill("zhao-sword",1); 
        if ( extra < 30) return notify_fail("�����չ÷�������������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("��÷����ȣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        extra +=dodge;
        me->add_temp("apply/attack", extra);
        msg = HIG "$N΢΢һЦ������һ����,��ʹ������Ԧ����������$n��\n"+HIW"��һ����÷��������" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "�ڶ�����÷�����ȣ�" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "����������亮÷��" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "���Ľ����꺮��ů��" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "���彣��÷�����ţ�"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -extra);
        me->start_busy(2); 
        return 1; 
}      
