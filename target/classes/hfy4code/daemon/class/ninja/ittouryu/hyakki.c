 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,adjust;
        int count;
        object weapon,targetweapon;
        extra = me->query_skill("ittouryu",1);
        
        if ( extra < 150) return notify_fail("��ģ�һ���������ݻ��������죡\n"); 
        if( !target ) target = offensive_target(me);    
        if( !target     
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۰ٹ�ҹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
//      if(me->query_temp("timer/hyakki")+60>time())
//              return notify_fail("���ɱ���Ѿ����޷��ڶ�ʱ�����ٳ���һ�С�\n");
        if (me->query("class")=="shaolin")  extra = extra *5/2;    
        msg = HIR  "\n\n$NͻȻ���쳤����ͷ�����������ֱ����$n��ϡ����$N��ͫ�����ڱ�ɺ�ɫ��
$N�͵�����$n��������һ��������ǿһ��-���ٹ�ҹ�񡹣���$n������һƬ�����С�
" NOR;
        count=0;
        
        adjust = 440-me->query_skill("blade")>0?0:440-me->query_skill("blade");
//      message_vision("adjust is "+(string)adjust+"\n",me);    
//      me->set_temp("timer/hyakki",time());
        me->add_temp("apply/attack",adjust);
        me->add_temp("apply/damage",extra);
        msg += HIC  "�ٹ�Ϯ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIG  "�ٹ�壡��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIB  "�ٹ��飡��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIY  "�ٹ�ͻ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIM  "�ٹ�׹����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIW  "�ٹ�ն����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIR  "�𣡣�����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg="\n\n";
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-adjust);
        if(!count)
                msg+=HIB"$n������Ͼ������$N���еĹ����������˵��
�����ֵ����ˣ�����\n"NOR;
        else if(count<4)
                msg+=HIY"ͻȻ��һ����Ѫ���䣬��֮$n�Ƴ����⣬���������½�
����һ�ࡣ\n"NOR;
        else if(count<7)
                msg+=HIM"ͻȻ��һ����Ѫ���䣬��֮$n�Ƴ����⣬���������½�
����˺���ţ�����������...��,
$N�ӵ������ٹ�ҹ�񡱡�\n"NOR;
        else
                msg+=HIR"ͻȻ��һ����Ѫ���䣬��֮$N�Ƴ����⣬������Ѫ���е�$n
������˵������Цֹǧ�򣡡�\n"NOR;
        message_vision(msg,me,target);
        if (count>3) target->start_busy(3);
                else target->start_busy(count);
        if (count>5) me->start_busy(3);
                else me->start_busy(8-count);
        
        return 1;
}     
