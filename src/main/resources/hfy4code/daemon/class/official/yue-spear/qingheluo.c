#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int tmp,int extra,object weapon);
int perform(object me, object target)
{
        string forceskill,msg;
        int extra, exp_bonus;
        int tmp;
        object weapon;
        forceskill= me->query_skill_mapped("force"); 
        weapon=me->query_temp("weapon");
        extra = me->query_skill("yue-spear",1);
        if ( extra < 150) 
                return notify_fail("���������ƽǹ�����������죡\n");
        tmp = me->query_skill("manjianghong",1);
//        if ( tmp < 60 )return notify_fail("��ġ��������ķ������������죡\n");
	if(me->query("class") != "quest_npc")
		return notify_fail("�㲻��ʹ����һ��!\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ݺ����¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
                
        exp_bonus = me->query("combat_exp")/1000*extra/2000;    
        if (exp_bonus>extra*4) exp_bonus=extra*4;
        
        forceskill = (string) me->query_skill_mapped("force");
        if ( forceskill != "manjianghong") tmp = 0;
                
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra/2);  
        msg = HIW "\n$N���쳤Х����Ȼ����ֱ������������$w"+HIW"�û���ǧ��ìӰ�����ǡ�������ƽǹ����\n��ս�޵�֮ʽ��--��-��-��-��--��!!"NOR+HIC"\n\n��\n$N����$w"HIC"ֱָ���գ���Ȼֱ��$n!" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "����\n$Nŭ��һ����ǧ��ìӰ���κ��˰�ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "����Ȼ\n$N��ǹ֮�������м䣬ǹͷǹβ���������������$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		me->add_temp("apply/damage",extra);  
    msg = HIR  "�ݺ�����\n$N����$w"+HIR"������Ҷ���޴����ڣ�����ǹӰ��һ����ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra); 
    msg = HIC  "��˻\n$w"+HIC"�������磬�������죬�·������ڣ�" NOR;
       COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIC  "Ѫ��\n$N����$w"+HIC"ǹͷ����ٿ�ñ������������Ѫ�⣡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "��\n����һ��ͻ��������$N����$w"+HIW"ǹӰ��ʧ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra/2); 
           
        if (me->query_busy()<6) me->start_busy(6);   
        return 1;
}       
