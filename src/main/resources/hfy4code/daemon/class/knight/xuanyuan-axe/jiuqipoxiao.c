#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,attack,armor;
        object weapon;
        extra = me->query_skill("xuanyuan-axe",1);
        
        attack = me->query_skill("axe");
        if(me->query("class")!="knight")
                return notify_fail("ֻ�п���ֵ��Ӳ���ʹ���������������ľ�����\n");
        if ( extra < 160) return notify_fail("�����ԯ�������������죡\n");
        
        
        if (userp(me) && me->query_skill_mapped("force") != "longlife-force")
                return notify_fail("��ԯ������Ҫ����������ͣ�\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۾���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
//        if (me->query_temp("timer/jiuqipoxiao")+30>time())
//                return notify_fail("�۾��������ݲ�������ʹ�á�\n");     
                
        armor = target->query("resistance/kee");        
        weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",extra*3);
		me->add_temp("apply/damage",extra*3);
        msg = HIY  "$N���е�"+ weapon->name()+HIY"�趯���ٶ��������죬������������\n������"+weapon->name()+HIY"ͻȻ������������$n"NOR+HIY"����һʽ������������������\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "��⣡" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW  "��ʯ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "����ɽ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		msg = HIB  "��������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		msg = HIC  "�ƾ�����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra*3);
		me->add_temp("apply/damage",-extra*3);
        if ( extra >= 210&&me->query_temp("timer/jiuqipoxiao")+30<time())
        {
        msg = HIR  "�������£�" NOR;
        target->set_temp("resistance/kee",-armor);
        me->add_temp("apply/attack",attack*2);
		me->add_temp("apply/damage",attack*7);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-attack*2);
		me->add_temp("apply/damage",-attack*7);
        target->set_temp("resistance/kee",0);
        }
        if (me->query_busy()<3) 
                me->start_busy(3);
        me->set_temp("timer/jiuqipoxiao",time());
        return 1;
}     
