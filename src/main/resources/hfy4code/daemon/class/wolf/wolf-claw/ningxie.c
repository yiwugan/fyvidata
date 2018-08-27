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
                return notify_fail("只有狼山弟子才能使出「凝血」的绝技。\n");
        
        extra = me->query_skill("wolf-claw",1) ;
        if(extra >= 401) extra = 401; 
        
        if(extra < 101) 
                return notify_fail("你的「地狱狼魂爪」不够熟练！\n");
        
        if(me->query("force")<50 && userp(me))
                return notify_fail("你的内力不够，使不出「凝血」绝技。\n");
        
        if(me->query("sen")<50 && userp(me))
                return notify_fail("你的神不够，使不出「凝血」绝技。\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(WHT"「凝血」只能对战斗中的对手使用。\n"NOR); 
        
        msg = HIB "$N"HIB"双爪回环各划一个弧形，一股森森的阴风直扑$n。\n" NOR;
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
                msg = RED"\n暗劲袭来，$n"+NOR WHT"只觉得彻骨冰冷，如坠幽冥，混身血液几乎凝固！ \n" NOR;
                target->receive_wound("sen", (mysen/2+random(mysen)), me);
                target->receive_wound("gin", (mygin/2+random(mygin)), me);
                target->receive_wound("kee", ((int) me->query("max_kee")/2+random(mykee/2)), me);
                target->start_busy(1);
                me->start_busy(2);
//                if (userp(me)) me->start_busy(4);  //player use,selfbusy 4
//                        else me->start_busy(3);
        }
        else {
                msg = HIY"\n$n"+HIY"连忙腾身后越，闪开了$N"+HIY"暗劲的致命一击。 \n" NOR;
                me->start_busy(2);
        }
        message_vision(msg, me, target);
           if (userp(me)) me->add("sen",-50);
        if (userp(me))  me->add("force",-50);
        return 1;
}
