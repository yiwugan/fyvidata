#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object wolf;
        int summonwolf, exp;
        int guard;
        
        if ((string)me->query("class") != "wolfmount")
                return notify_fail("只有狼山弟子才可以驱狼助阵。\n");
        if ( me->is_busy() )
                return notify_fail("你现在正忙，无法驱狼助阵。\n");
        if( !me->is_fighting() )
                return notify_fail("好象没有人要杀你！\n");
        if(((int)me->query("sen")< 80)||((int)me->query("gin")<80))
                return notify_fail("你的精神状况太差了，恐怕无法有效的驱狼助阵。\n");
                
        summonwolf = (int)me->query_skill("summonwolf",1);
        exp = (int)me->query("combat_exp");
        if(summonwolf < 25 )
                return notify_fail("你的唤狼之术不够熟练，无法唤出狼来！\n");   
        
        if(summonwolf <150) guard =1;
                else guard= 2;
        
        if (summonwolf <180)
        if (environment(me) && !environment(me)->query("outdoors"))
                return notify_fail("你不可引狼入室！\n"); 
        if (!environment(me)->query("outdoors"))
                guard = 1;
                
        if( me->query_temp("max_guard") > guard )
                return notify_fail("好象附近已经没有狼了。\n"); 
        seteuid(getuid());
        if (summonwolf<100){    
                me->receive_damage("sen",80);
                me->receive_damage("gin",80);
        } else {
                me->receive_damage("sen",80+(summonwolf-80)/3);
                me->receive_damage("gin",80+(summonwolf-80)/3);
           }
        wolf= new("/obj/npc/wolf");
        wolf->move(environment(me));
        wolf->invocation(me, (summonwolf));
        wolf->set("possessed", me); 
        if (summonwolf<50)
                wolf->set_name("杂毛恶狼",({ "wolf" }));
        else if (summonwolf<75)
                wolf->set_name(WHT"灰毛恶狼"NOR,({ "wolf" }));
        else if (summonwolf<100)
                wolf->set_name(YEL"黄毛恶狼"NOR,({ "wolf" }));
        else if (summonwolf<125)
                wolf->set_name(RED"红毛恶狼"NOR,({ "wolf" }));
        else if (summonwolf<150)
                wolf->set_name(HIW"白毛恶狼"NOR,({ "wolf" }));
        else if (summonwolf<175)
                wolf->set_name(HIR"赤毛恶狼"NOR,({ "wolf" }));
        else 
                wolf->set_name(HIY"金毛狼王"NOR,({ "wolf" }));  
        me->add_temp("max_guard",1);
        me->remove_all_killer();
        message_vision(HIB "\n$N仰天狼嚎“呜～嗷～～，呜～嗷”，顿时漫山遍野群狼齐哮。\n" NOR, me);     
        message_vision( "\n\n$N恶狠狠地扑了上来。\n" , wolf);
        return 1;
} 
int help(object me)
{
        write(@HELP
指令格式：xiao
 
这个指令让狼山弟子呼唤狼来保护自己。
能否招呼出狼，呼出狼水平的高低就要看你的技能了。
 
HELP
    );
    return 1;
}     
