 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        int orforce; 
 
        if (me->query("class")!="quanli")
                return notify_fail ("���Ƹ����ۣ�ֻ�в�������ֵܽ��ò���ʹ�á�\n");
        if(me->is_busy()) 
                return notify_fail("������û�գ���\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("���Ƹ����ۣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

 
        extra = me->query_skill("unarmed"); 
 
        if ( extra < 300) return notify_fail("�����å��ȭ���������죡\n"); 
 
        me->set("force_factor",(int)me->query_skill("force")/2); 
        orforce = (int) me->query("force"); 
        me->add("force",extra/3*20); 
        me->add_temp("apply/attack",extra); 
//        me->add_temp("apply/damage",extra/2); 
        msg = HIG  "$N"+HIG"ʹ���������µģ��Ƹ����ۣݣ��Դ�һ˿��ϧ֮ɫ��$n"+HIG"��ȫ��ҪѨ������\n" NOR; 
        message_vision(msg,me,target); 
        msg = HIG  "��һȭ��Ц���ʡ��ߡ�����һ��ָ���ɣ�" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIG  "�ڶ�ȭ��Ҷ���䡡�㡡�衡��������ɽ����" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIG  "����ȭ���䡡��硡�ơ������㡡ͷ������" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIG  "����ȭ���ء��ס�̫���ס��ġ���������������" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIG  "����ȭ�������¡��¡��ġ��塡�����أ���������" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIG  "����ȭ��ã��ã���ˮ�������ġ��죡����������" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIG  "����ȭ��Ц���ʡ�Ҷ���䡡�����硡�ƣ�������������" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIG  "���һȭ���ء��ס������¡������ˮ����������������" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->start_busy(5); 
        me->set("force_factor",0); 
        me->set("force", orforce); 
        me->add_temp("apply/attack",-extra); 
//        me->add_temp("apply/damage",-extra/2); 
        return 1; 
}        
