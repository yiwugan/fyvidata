 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,extra;
        extra=me->query_skill("eagle-claw",1);
        
//      if (me->query("class")!="fugui")
//              return notify_fail ("ֻ�������ĵ��Ӳ������ʮָ�����ݵ�Ҫ����\n");
        if(extra<130)
                return notify_fail("��ӥצ������Ϊ�������ߡ�\n");       
        if(me->query("force")<150)
                return notify_fail("�����������\n");   
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ʮָ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");        
                
        myexp = (int) me->query("combat_exp");
        if(me->query("class")!="fugui") myexp=myexp/10;
        yourexp = (int) target->query("combat_exp");
        lvl = (int) me->query_skill("unarmed")/10 + 3;
        if(me->query("class")!="fugui") lvl=lvl/10;
        msg = HIR "$Nʹ��ӥצ���еģ�ʮָ�����ݣ�˫�������������޵��������п���$n�Ĺؽ�Ҫ����\n" NOR;
        message_vision(msg, me, target);
        
        if (random(6)) {
                if( random(myexp * lvl)+myexp/2 > yourexp)
                {
                        msg = BLU"$n��ʧɫ���������У�����$N��ס����\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-150);
                        target->start_busy(5+random(5));
                        me->start_busy(1+random(2));
           } else  {
                        msg = YEL"$n���˷���������һȦһ����$N���ݲ�����ȥ��\n"NOR;
                        message_vision(msg,me,target);
                        me->start_busy(2);
                        }
        } else {        
                msg = HIG"$n�����ģ���и�ɻ���$Nһץ���У�������$n��$l��ȥ��"NOR;
                me->add_temp("apply/attack",extra);   
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra);  
                me->start_busy(1);
        }
        return 1;
}    
