 //neon@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, myexp, enemyexp, lvl;
        object weapon; 

        
        if((int)me->query_skill("snake-whip",1) < 50)
                return notify_fail("��������޷�������������\n");       
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon");
        
        lvl = (int) me->query_skill("snake-whip",1);
        if (me->query("force")<lvl/2+10)        
                return notify_fail("�������������\n");
        extra = me->query_skill("whip");
        if (me->query("class")=="yinshi") extra = extra*3;
        myexp = (int) me->query("combat_exp");
        if (me->query("class")=="yinshi") myexp = myexp*3;
        enemyexp= (int) target->query("combat_exp");
        
         if (me->query("class")== 0 )extra = extra*5;
         if (me->query("class")== 0 ) lvl = lvl/100;
           else lvl = lvl/300;
        
        msg = HIG"\n$N"+HIG"ͻȻ����һת������һ���������յ�$n"+HIG"��ͼ����ǰ��֮�ʣ�����"+ weapon->name() + HIG"��æ������������ͼȦ��$n"+HIG"˫��˫�š�\n" NOR;
        
        if (target->query("disable_type")&& target->query("is_unconcious")) {
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                return 1;
        }
        else message_vision(msg,me,target); 
        if (myexp/3 + random(myexp/80*extra) > enemyexp) {
                msg = GRN"\n����֮�价����ۣ�"+ weapon->name() + GRN"ǰ�����ҵط�ס$n"+GRN"������ʽ����$n"+GRN"�޷�������\n"
             
                   HIW"$n������Х��������ֹ��\n"NOR;
             
                        me->start_busy(lvl);
             
                if (userp(me))  me->add("force",-lvl*10);
             
                target->start_busy(lvl+2);
                target->receive_wound("kee", extra+random(extra*2), me);
                call_out("get_up",lvl+2, me,target);
                message_vision(msg,me,target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
                        
        }
        else {
                me->add_temp("apply/attack", extra/2);
                me->add_temp("apply/damage", extra/2);
                msg = GRN"\n�ۼ�$nͻ����Ȧ������$N����һ�����ϣ��Ľ�����������д̳���\n"NOR;

                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

                me->add_temp("apply/attack", -extra/2);
                me->add_temp("apply/damage", -extra/2);
                me->start_busy(2);
        }
        return 1;
} 
void get_up(object me,object target){
        
        if(!target||!living(target)||target->is_ghost())
                return ;
        message_vision(HIW "\n\n$N���һ����˫��һ��˫��һ�ţ�Ծ����Ȧ���ޣ���\n\n" NOR, target);
        
}     