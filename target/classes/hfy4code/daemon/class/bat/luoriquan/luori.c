#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        
        extra = me->query_skill("unarmed")*3;
         if (me->query("class")!="bat") extra /= 2;
        if (me->query_skill("luoriquan",1) < 220 && userp(me)) 
                return notify_fail("����ȭ����Ҫ220��������ȭ��\n");
        if( !target ) target = offensive_target(me);
        if( !target
                ||      !target->is_character()
                ||      !me->is_fighting(target) )
                return notify_fail("�����գ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        me->add_temp("apply/attack",extra/5);
        me->add_temp("apply/damage",extra/8);
        
        msg = HIM  "\n$N���췢��һ����Ц�������߸裬��ʱ�������Ϊ֮��ɫ��\n" NOR;
        message_vision(msg,me,target);
        msg = HIC    " һ������أ�
��������������������������ĸ��ۡ�\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  " ��Ȼ�������� 
�����������������������Ϸ���衣\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "�辡����Ц�� 
����������������������������Σ� \n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW   "������ʱ·�� 
����������������������������û��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR   "���������������գ���������������������\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra/5);
        me->add_temp("apply/damage",-extra/8); 
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}
