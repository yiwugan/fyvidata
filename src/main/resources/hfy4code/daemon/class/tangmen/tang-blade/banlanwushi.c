 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int extra;
    int tmp,chance;
    extra = me->query_skill("tang-blade",1);
    if ( extra < 70) return notify_fail("��ģ�����������ݻ��������죡\n");
        if (me->query("class")== "huashan") extra = extra * 8;
        if (me->query("class")=="legend") extra = extra * 2;
        if (me->query("class")=="official") extra = extra * 3;
        if (me->query("class")=="beggar") extra = extra * 5;
        
    if( !target ) target = offensive_target(me);
    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("�۰�����ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    me->add_temp("apply/attack",extra);
if (me->query("class")=="huashan")   me->add_temp("apply/damage",extra/2);
if (me->query("class")=="beggar")   me->add_temp("apply/damage",extra);
    msg = HIW  "\n$Nʹ������������еġ�����"+HIC"������ʽ"+HIW"�ݣ�һ��������ʽ�������������ţ���\n\n"NOR;
        msg+=HIC"��һ������������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   
        msg = HIC"�ڶ���������ΡΡ" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        msg = HIC "����������������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       
		msg = HIC  "���ĵ�����б�Ǻ�" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    
        msg = HIC  "���嵶���������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
 
    me->start_busy(3);
    me->add_temp("apply/attack",-extra);
if (me->query("class")=="huashan")    me->add_temp("apply/damage",-extra/2);
if (me->query("class")=="beggar")   me->add_temp("apply/damage",-extra);
    return 1;
}  
