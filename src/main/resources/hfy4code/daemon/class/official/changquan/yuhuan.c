 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int orforce;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        if(me->query("class") != "official" && me->query("class") != "shaolin")            
                return notify_fail("��ȷ����ֵ��ӣ�Ҳ�ǳ�͢��Ա������������ԧ��ȭ��\n");
        extra = me->query_skill("unarmed");
        if ( extra < 220) return notify_fail("������ֳ�ȭ���������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ԧ��ȭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
//        if (me->query("force")<me->query("force_factor")*3)
//                return notify_fail ("�������������\n");
        me->add("force_factor",extra/5);
        orforce = (int) me->query("force"); 
        me->add("force",extra/3*10); 
        if (me->query("class") == "shaolin" ) extra *= 4;
        	if (me->query("once_xman")==1 ) me->add_temp("apply/str",extra/100);
        me->add_temp("apply/attack",extra/3);
        msg = HIY  "$Nʹ�����ֳ�ȭ�еģ���ԧ��ȭ�ݣ�һ��������ʽ��$n������\n" NOR;
        message_vision(msg,me,target);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIY  "ǰһȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIY  "�����һȭ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		if (me->query_busy()<3) me->start_busy(3);
        me->set("force_factor",0);
        me->set("force", orforce); 
//        if((int)me->query("force") < 0 ) me->set("force",0);
        me->add_temp("apply/attack",-extra/3);
        if (me->query("once_xman")==1 ) me->add_temp("apply/str",-extra/100);
        return 1;
}  
