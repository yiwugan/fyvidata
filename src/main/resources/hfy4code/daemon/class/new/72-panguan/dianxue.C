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
     //   if(me->query("class")!="beggar" && userp(me))
       //         return notify_fail("�۰��־���ֻ���ڸ�ؤ����ӣ�\n");
        
        if((int)me->query_skill("72-panguan",1) < 50)
                return notify_fail("�����ʮ��·�йٱʻ�����������\n");       
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۵�Ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon");
        
        lvl = (int) me->query_skill("72-panguan",1);
        if (me->query("force")<lvl/2+10)        
                return notify_fail("�������������\n");
        
        lvl = lvl /100;
        if (lvl >= 9) lvl =9;
        
        extra = me->query_skill("dagger");
         if (me->query("class")== 0 )extra = extra*3;
         if (me->query("class")> 0 ) lvl = lvl/3;
         
        myexp = (int) me->query("combat_exp");
       // if (me->query("class")=="yinshi") myexp = myexp*3/2;
        enemyexp= (int) target->query("combat_exp");
        
        msg = HIY"\n˵ʱ����ʱ�죬$N"+HIY"���ֲ�ָ������"+ weapon->name() + HIY"���ֵ�����ֱ����$n"+HIY"�羮�����ж�Ѩ��\n" NOR;
        
        if (target->query("disable_type")&& target->query("is_unconcious")) {
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                return 1;
        }
        else message_vision(msg,me,target); 
        if (myexp/3 + random(myexp/80*extra) > enemyexp) {
                msg = YEL"һʱ�������У�"+ weapon->name() + YEL"�Ѵ���$n"+YEL"Ѩ����$n"+YEL"��ʱ����һ�ͣ����������У��ڽ��˺�\n"NOR;
                  
                        me->start_busy(lvl);

                target->start_busy(lvl+1);
                target->receive_wound("kee", extra+random(extra*3), me);
              
                message_vision(msg,me,target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
                        
        }
        else {
                me->add_temp("apply/attack", extra/2);
                me->add_temp("apply/damage", extra/2);
                msg = YEL"$n�ƺ��Ѿ��з����������������ܿ���ǰҪѨ��$Nֻ��˳�Ƹĵ�Ϊ�̣�ȫ��һ����"NOR;

                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

                me->add_temp("apply/attack", -extra/2);
                me->add_temp("apply/damage", -extra/2);
                me->start_busy(2);
        }
        return 1;
} 
   