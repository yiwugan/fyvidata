#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int tmp,int extra,object weapon);
int perform(object me, object target)
{
        string forceskill,msg;
        int extra, exp_bonus;
        int tmp,dmg,attack;
        int myexp,tarexp,lvl;
        object weapon;
        forceskill= me->query_skill_mapped("force"); 
        weapon=me->query_temp("weapon");
        extra = me->query_skill("yue-spear",1);
        if(me->query("class")!="official")
        	return notify_fail("ֻ�г�͢��Ա����ʹ�á��ݺ����¡���\n");
        if ( extra < 60) 
                return notify_fail("���������ƽǹ�����������죡\n");
        tmp = me->query_skill("manjianghong",1);
        if ( tmp < 60 )return notify_fail("��ġ��������ķ������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ݺ����¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
                
        exp_bonus = me->query("combat_exp")/1000*extra/2000;    
        if (exp_bonus>extra*4) exp_bonus=extra*4;
        
        myexp=me->query("combat_exp");
        tarexp=target->query("combat_exp");
        lvl = me->query_skill("yue-spear",1);
        
        if ( me->query("family/master_id")!="master yue" 
                ||extra <= 150){ 
                me->add_temp("apply/attack", 2*tmp+exp_bonus/4);    
                me->add_temp("apply/damage", 2*extra+ exp_bonus);
        msg = HIW  "$N���쳤Х������$w"+HIW"�û���ǧ��ìӰ�����ݺ᡻����ɨ���棡��\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                if( random(myexp)*(lvl/50)+random(myexp/2)>tarexp/2+random(tarexp/3) ){
                	message_vision(WHT"$N�·�������ս������ǰǧ������ӭ��ɱ�˹�����$N��ս�ľ����������ᣡ\n"NOR,target);
                	target->receive_wound("sen",lvl*2);
                	target->receive_wound("kee",lvl*3);
                }                
        msg = HIW  "$N���쳤Х������$w"+HIW"�û���ǧ��ìӰ�������¡������̰˷�����\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		if( random(myexp)*(lvl/50)+random(myexp/2)>tarexp/2+random(tarexp/3) ){
                	message_vision(WHT"$N�·�������ս������ǰǧ������ӭ��ɱ�˹�����$N��ս�ľ����������ᣡ\n"NOR,target);
                	target->receive_wound("sen",lvl*2);
                	target->receive_wound("kee",lvl*3);
                }                
                me->add_temp("apply/attack", -2*tmp-exp_bonus/4);
                me->add_temp("apply/damage", -2*extra-exp_bonus);
                if (me->query_busy()<2) me->start_busy(2); 
                return 1;
        }
        
        else {
        attack = me->query_skill("spear");
        forceskill = (string) me->query_skill_mapped("force");
        if ( forceskill != "manjianghong") attack = extra/2;
        dmg = attack + tmp;
        me->add_temp("apply/attack",attack*2);
        me->add_temp("apply/damage",dmg);  
        msg = HIW "\n$N���쳤Х����Ȼ����ֱ������������$w"+HIW"�û���ǧ��ìӰ�����ǡ�������ƽǹ����\n��ս�޵�֮ʽ��--��-��-��-��--��!!"NOR+HIC"\n\n��\n$N����$w"HIC"ֱָ���գ���Ȼֱ��$n!" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "����\n$Nŭ��һ����ǧ��ìӰ���κ��˰�ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "����Ȼ\n$N��ǹ֮�������м䣬ǹͷǹβ���������������$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		me->add_temp("apply/damage",extra*4);  
    msg = HIR  "�ݺ�����\n$N����$w"+HIR"������Ҷ���޴����ڣ�����ǹӰ��һ����ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*4); 
    msg = HIC  "��˻\n$w"+HIC"�������磬�������죬�·������ڣ�" NOR;
       COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIC  "Ѫ��\n$N����$w"+HIC"ǹͷ����ٿ�ñ������������Ѫ�⣡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "��\n����һ��ͻ��������$N����$w"+HIW"ǹӰ��ʧ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-attack*2);
        me->add_temp("apply/damage",-dmg); 
           
        if (me->query_busy()<5) me->start_busy(5);   
        } 
        return 1;
}       
