#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int tmp,int extra,object weapon);
int perform(object me, object target)
{
        string forceskill,msg;
        int extra, exp_bonus;
        int tmp,skill;
        object weapon;
        
        weapon=me->query_temp("weapon");
        extra = me->query_skill("feiyun-spear",1);
        tmp = me->query_skill("yue-spear",1);
        skill = me->query_skill("spear",1);
        tmp = extra * tmp * skill;
        if (!me->query("marks/�ٸ�/����")) return notify_fail("��û�еõ����ɵ�ָ�㣬ʹ�����˷���ǹ����\n");

        
        if ( extra < 150) 
                return notify_fail("��ķ���ǹ�����������죡\n");
        
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������䡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
                
        exp_bonus = me->query("combat_exp")/1000*extra/2000;    
        if (exp_bonus>extra*4) exp_bonus=extra*4;
     
                        
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra/2);  
        msg = HIW "\n$N�����������˲�����ɽ������$w"+HIW"ʹ��һ�С����壭�ӣ��䣭����"NOR+HIC"\n\n��Х����ӵ����\n$N����$w"HIC"ֱָ���գ���Ȼֱ��$n!" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIY  "�彫�����ۧ�e\n$Nŭ��һ����ǧ��ìӰ���κ��˰�ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIB  "δ��ʫ������\n$N��ǹ֮�������м䣬ǹͷǹβ���������������$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		me->add_temp("apply/damage",extra);  
    msg = HIG  "�ƹ��̲�����ˮ\n$N����$w"+HIG"������Ҷ���޴����ڣ�����ǹӰ��һ����ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra); 
    msg = HIM  "һ��˿��������\n$w"+HIM"�������磬�������죬�·��������ڣ�" NOR;
       COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIC  "���ж����Ե��o\n$N����$w"+HIC"ǹͷ����ٿ�ñ������������Ѫ�⣡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "���ﾪ�ɾ���Ÿ\n����һ��ͻ��������$N����$w"+HIW"ǹӰ��ʧ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra/2); 
           
        if (me->query_busy()<6) me->start_busy(6);   
        return 1;
}       