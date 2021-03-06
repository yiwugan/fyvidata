 // silencer@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target, int amount)
{
        int skill, per, base;
        
        if(me->query("class") != "shenshui")
                return  notify_fail("［迷魂大法］是神水宫的绝技！\n");
        if (me->query_skill("nine-moon-spirit",1)<50)
                return notify_fail ("你的[姹女神功]太差了。\n");
        if (me->query_skill_mapped("force") != "nine-moon-force")
                return notify_fail("「迷魂大法」需要九阴心经的配合。\n");
        if((int)me->query("timer/mihunshu") + 14 > time())
                return notify_fail(HIM"「迷魂大法」不能连续使用。\n"NOR);
        if( !me->is_fighting() )
                return notify_fail("［迷魂大法］只能在战斗中使用。\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("你的内力不够。\n"); 
                
        if( !target || target==me ) target = offensive_target(me);
        if (!target) return notify_fail("你要对谁施展［迷魂大法］？\n");
        
        skill = me->query_skill("nine-moon-spirit",1);
        me->add("force", -100);
        per = me->query("per");
        message_vision(
                
                HIG"\n$N停住了手，用飘飘的眼光温柔地瞧着$n"+HIG"，媚眼如丝，巧笑盈盈 ...\n\n"NOR
                WHT"$N缓缓将手前伸，这只手纤细、柔美，而毫无瑕疵，带着种凄秘的妖艳之气。\n\n\n" NOR, me, target); 
        if (userp(target)) base=(int)me->query("combat_exp");
                else base=(int)me->query("combat_exp")*per/10;
        
        if( random(target->query("combat_exp")) > base ) {
                message_vision(HIY"$N避开$n的目光，就势斜斩"+HIY"$n脉门！\n"NOR, target, me);
                me->set("timer/mihunshu",time());
                return 1;
        }
        message_vision(HIM"一时之间，$N"+HIM"心中一荡，似已将窒息．眼勾勾地看着$n"+HIM"的纤纤手指拂过胸前。\n\n"NOR,target,me);
   message_vision(RED"$N"+RED"心头如针刺般剧痛，幽幽寒气渗入血脉。\n\n"NOR,target);
        target->receive_damage("sen", skill*per/15+2*random(skill));
        target->receive_damage("kee", skill*per/20+2*random(skill));
        target->set_temp("last_damage_from",me);
        COMBAT_D->report_status(target);
        COMBAT_D->win_lose_check(me,target,1);
        if (!target->is_busy()) target->start_busy(1);
        me->set("timer/mihunshu",time());
        return 1;
}      
