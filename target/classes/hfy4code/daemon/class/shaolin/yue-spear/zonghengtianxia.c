#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int tmp,int extra,object weapon);
int perform(object me, object target)
{
    string forceskill,msg;
        int extra;
        int tmp;
        object weapon;
        
        weapon=me->query_temp("weapon");
    extra = me->query_skill("yue-spear",1);
    if ( extra < 60) 
        return notify_fail("���������ƽǹ�����������죡\n");
        forceskill = (string) me->query_skill_mapped("force");
    if ( forceskill != "manjianghong")
        return notify_fail("���ݺ����¡���Ҫ���������ķ�������ϣ�\n");
    tmp = me->query_skill("manjianghong",1);
    if ( tmp < 60 )return notify_fail("��ġ��������ķ������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("���ݺ����¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        if ((string)me->query("class") != "official"||extra < 150){ 
                me->add_temp("apply/attack", tmp);    
                me->add_temp("apply/damage", extra);
        msg = HIR  "$N���쳤Х������$w�û���ǧ��ìӰ��һʽ���ݺ����¡�������˷�ֱ��$n����\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -tmp);
                me->add_temp("apply/damage", -extra);
                me->start_busy(2); 
                return 1;
        }
        
        if (!me->query("marks/�ٸ�/����") && extra <180 ) {
                me->add_temp("apply/attack", tmp);    
                me->add_temp("apply/damage", extra);
        msg = HIR  "$N���쳤Х������$w�û���ǧ��ìӰ��һʽ���ݺ����¡�������˷�ֱ��$n����\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -tmp);
                me->add_temp("apply/damage", -extra);
                me->start_busy(2);   
                return 1;
        }
                
/*        if (extra < 150||!me->query("marks/�ٸ�/����")) {
                me->add_temp("apply/attack", tmp);    
                me->add_temp("apply/damage", extra);
        msg = HIR  "$N���쳤Х������$w�û���ǧ��ìӰ��һʽ���ݺ����¡�������˷�ֱ��$n����\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -tmp);
                me->add_temp("apply/damage", -extra);
                me->start_busy(2);   
        } */
        else {
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
    msg = HIW "\n$N���쳤Х����Ȼ����ֱ������������$w�û���ǧ��ìӰ�����ǡ�������ƽǹ����\n��ս�޵�֮ʽ��--��-��-��-��--��!!"NOR+HIC"\n\n��\n$N����$wֱָ���գ���Ȼֱ��$n!" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "����\n$Nŭ��һ����ǧ��ìӰ���κ��˰�ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "����Ȼ\n$N��ǹ֮�������м䣬ǹͷǹβ���������������$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "�ݺ�����\n$N����$w������Ҷ���޴����ڣ�����ǹӰ��һ����ֱ��$n��" NOR;
        me->add_temp("apply/attack",tmp*2);
        me->add_temp("apply/damage",extra*2);  
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "��˻\n$w�������磬�������죬�·������ڣ�" NOR;
        me->add_temp("apply/attack",-tmp*2);
        me->add_temp("apply/damage",-extra*2); 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIC  "Ѫ��\n$N����$wǹͷ����ٿ�ñ������������Ѫ�⣡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "��\n����һ��ͻ��������$N����$wǹӰ��ʧ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    
    if (!me->query("marks/�ٸ�/����")) { me->start_busy(7);}
    else     me->start_busy(6);
    
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        } 
        return 1;
} 
