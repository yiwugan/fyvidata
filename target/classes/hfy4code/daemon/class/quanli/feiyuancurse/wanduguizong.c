 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int myexp,yourexp,lvl,extra; 
        int damage; 
        if (me->query("class")!="quanli")
                return notify_fail ("ֻ�в�������Ӳ���ʹ�ã��򶾹��ڣݡ�\n");

        if( !target ) target = offensive_target(me); 
 
        if( !target 
        ||      !target->is_character() 
        ||      target->is_corpse() 
        ||      target==me) 
                return notify_fail("��Ҫ��˭ʩչ���򶾹��ڣݣ�\n"); 
 
        if((int)me->query("kee") < 100 ) 
                return notify_fail("�����Ѫ������\n"); 
        extra = me->query_skill("feiyuancurse",1); 
        if( extra < 70) return notify_fail("��ģ۷�ԩ�������ݻ�����������\n"); 
        msg = MAG "$N"+MAG"�����ע��ʹ����ԩ�����������������ģ��򶾹��ڣݣ�͵͵����$n"+MAG"������\n\n" NOR; 
        me->receive_wound("kee", 100); 
 
        myexp = me->query("combat_exp"); 
        yourexp = target->query("combat_exp"); 
        lvl = me->query_skill("feiyuancurse") / 10 ; 
                damage = lvl*2 + random(extra*4); 
        if( random(myexp * lvl) > yourexp* lvl/4 ) 
        { 
        msg +=  RED "����֮��������Ϣ������$n"+RED"�����ڣ�����\n" NOR; 
        message_vision(msg,me,target); 
        target->apply_condition("wanzhuo",random(lvl)+10); 
        target->receive_damage("gin", damage, me); 
        target->receive_wound("gin", damage, me); 
        COMBAT_D->report_status(target);
        COMBAT_D->win_lose_check(me,target,1);
        }  
                else 
                { 
                msg += "���Ǳ�$n�����ˣ���\n"; 
                message_vision(msg,me,target); 
           target->kill_ob(me); 
                } 
 
        me->start_busy(2); 
        return 1; 
}  
