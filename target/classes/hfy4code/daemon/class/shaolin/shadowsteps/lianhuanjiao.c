 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        if( !target ) target = offensive_target(me); 
        if(me->query("class")!="swordsman")
                return notify_fail("�����ٻ�Ӱ�����ţ�ֻ����ɽׯ�ĵ��Ӳ����ã�\n");
        
//      if (userp(me) && me->query_skill_mapped("force") != "cloudforce")
//              return notify_fail("�����ٻ�Ӱ�����ţ���Ҫ�۵����ķ��ݵ���ϣ�\n");
                
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����ٻ�Ӱ�����ţ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        extra = me->query_skill("shadowsteps",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIR  "$Nʩչ�������ٻ�Ӱ�����ţݣ����μ�����ת��һ����Ӱ��ͻȻ��$n�ɳ�һ�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"����");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "��Ӱ���ַɳ�һ�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"����");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N���ν��ȣ���������һ�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"����");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        if (me->query_busy()<2) me->start_busy(2);
        return 1;
}   
