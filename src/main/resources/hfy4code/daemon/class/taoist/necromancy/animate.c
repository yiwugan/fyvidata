 // animate.c
inherit F_CLEAN_UP; 
int cast(object me, object target)
{
        if(me->query("class")!="taoist")
                return notify_fail("只有三清宫的弟子才能够使用三清道术。\n");
                
        if( (int)me->query_skill("necromancy",1) < 10 )
                return notify_fail("你的法术不够高！\n");
        
        if( me->is_fighting() ) 
                return notify_fail("战斗中不能驱尸！\n");
        
        if( !target || !target->is_corpse() ) 
                return notify_fail("你要驱动哪一具尸体？\n");
        
        if( (int)me->query("mana") < 50 || me->query("sen")<20)
                return notify_fail("你的法力不够了！\n"); 
        message_vision("$N对著地上的$n喃喃地念了几句咒语，$n抽搐了几下竟站了起来！\n", me, target); 
        target->animate(me, (int)me->query_skill("spells"));
        me->add("mana", -50);
        me->receive_damage("sen", 10);
        return 1;
}
       
