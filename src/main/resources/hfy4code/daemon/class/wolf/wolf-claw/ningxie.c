#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int mykee,mysen,mygin;
        int myexp;
        
        if(me->query("class")!="wolfmount")
                return notify_fail("ֻ����ɽ���Ӳ���ʹ������Ѫ���ľ�����\n");
        
        extra = me->query_skill("wolf-claw",1) ;
        if(extra >= 401) extra = 401; 
        
        if(extra < 101) 
                return notify_fail("��ġ������ǻ�צ������������\n");
        
        if(me->query("force")<50 && userp(me))
                return notify_fail("�������������ʹ��������Ѫ��������\n");
        
        if(me->query("sen")<50 && userp(me))
                return notify_fail("����񲻹���ʹ��������Ѫ��������\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(WHT"����Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR); 
        
        msg = HIB "$N"HIB"˫צ�ػ�����һ�����Σ�һ��ɭɭ������ֱ��$n��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        myexp=me->query("combat_exp");
        
        if (myexp>= 150000000) myexp = 150000000;
        
        if (userp(me)){
        	mykee=me->query("max_kee")/2;
        	mysen=me->query("max_sen")/2;
        	mygin=me->query("max_gin")/2;
        }
        else{
        	mykee=me->query("max_kee")/40;
        	mysen=me->query("max_sen")/40;
        	mygin=me->query("max_gin")/40;
        	myexp=myexp/4;
        }
        if(random(extra*extra*extra/2 + myexp)+ myexp > random(target->query("combat_exp"))) {
                msg = RED"\n����Ϯ����$n"+NOR WHT"ֻ���ó��Ǳ��䣬��׹��ڤ������ѪҺ�������̣� \n" NOR;
                target->receive_wound("sen", (mysen/2+random(mysen)), me);
                target->receive_wound("gin", (mygin/2+random(mygin)), me);
                target->receive_wound("kee", ((int) me->query("max_kee")/2+random(mykee/2)), me);
                target->start_busy(1);
                me->start_busy(2);
//                if (userp(me)) me->start_busy(4);  //player use,selfbusy 4
//                        else me->start_busy(3);
        }
        else {
                msg = HIY"\n$n"+HIY"��æ�����Խ��������$N"+HIY"����������һ���� \n" NOR;
                me->start_busy(2);
        }
        message_vision(msg, me, target);
           if (userp(me)) me->add("sen",-50);
        if (userp(me))  me->add("force",-50);
        return 1;
}
