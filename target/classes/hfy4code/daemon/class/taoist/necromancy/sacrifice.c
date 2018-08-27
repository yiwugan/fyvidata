 // sacrifice.c silencer@fy
#include <ansi.h>
inherit SSERVER; 
int cast(object me, object target)
{ 
        object corpse;
        int i, num;
        
        if(me->query("class")!="taoist")
                return notify_fail("只有三清宫的弟子才能够使用三清道术。\n");
        
        if((int)me->query_skill("necromancy",1) < 150 )
                return notify_fail("你的三清道术不够高！\n");
        
        if(me->is_fighting()) 
                return notify_fail("战斗中不能施此法.\n");
        
        if((int)me->query("mana") < 100 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的神不够！\n");
        
        num = (me->query_skill("necromancy",1)-150)*3/2+10;
        
        if  (me->query("timer/zombie")+600<time()) 
                me->set("timer/zombie_n",0);
        
        if (!me->query("timer/zombie_n")) me->set("timer/zombie",time());
        
        if (me->query("timer/zombie")+600>time() && me->query("timer/zombie_n")>num)
                return notify_fail("你的神力已衰，需要休息一会儿才能继续召唤。\n");
        
        
        seteuid(getuid());
        corpse = new("/obj/item/mocorpse");   
        corpse->set("name",HIR"恶魔"NOR);
        corpse->set("victim_name",HIR"恶魔"NOR);
        corpse->set("no_burn",1);
        corpse->set("long",
                
"这是一团阴界邪恶精灵聚成的鬼气，青面獠牙，还长着一只犄角。\n");
        corpse ->move(environment(this_player()));
        me->add("mana", -100);
        me->receive_damage("sen", 100);
        me->add("timer/zombie_n",1);
        me->start_busy(1);
        
        message_vision(HIB"$N口中喃喃地念著咒文，左手一挥，忽然，一团黑烟从地面上冒起！\n" NOR,me);
        message_vision(HIB"片刻，黑烟凝聚成人形，却没有一点生气。\n"NOR,me);
        return 1;
}
              
