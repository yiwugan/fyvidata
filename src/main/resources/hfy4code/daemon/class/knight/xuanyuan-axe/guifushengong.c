#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int skill,n,extra;
        object weapon;
        skill = me->query_skill("xuanyuan-axe",1);
        extra = me->query_skill("axe");
        if ( skill < 40) return notify_fail("�����ԯ�������������죡\n");
        
        if (userp(me) && me->query_skill_mapped("force") != "longlife-force")
                return notify_fail("��ԯ������Ҫ����������ϣ�\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۹��񹤣�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (extra>140 && me->query("class")=="knight") n=0;
                else if (extra>100) n=1;
                else n=2; 
        weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",extra*3/2);
        me->add_temp("apply/damage",extra*3);
        msg = HIB  "$N�������ŭ���������е�"+ weapon->name()+HIB"������������$n"+HIB"����һ���۹��ݣ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "$N��Ǹ��ֱ�죬˫����Ȼ��֣����е�"+ weapon->name()+HIB"�طɣ�����������һ�����񹤣ݣ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra*3/2);
        me->add_temp("apply/damage",-extra*3);
        if (me->query_busy()<2+n) 
                me->start_busy(2+n);
        return 1;
}
