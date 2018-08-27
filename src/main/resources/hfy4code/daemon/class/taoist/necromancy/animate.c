 // animate.c
inherit F_CLEAN_UP; 
int cast(object me, object target)
{
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n");
                
        if( (int)me->query_skill("necromancy",1) < 10 )
                return notify_fail("��ķ��������ߣ�\n");
        
        if( me->is_fighting() ) 
                return notify_fail("ս���в�����ʬ��\n");
        
        if( !target || !target->is_corpse() ) 
                return notify_fail("��Ҫ������һ��ʬ�壿\n");
        
        if( (int)me->query("mana") < 50 || me->query("sen")<20)
                return notify_fail("��ķ��������ˣ�\n"); 
        message_vision("$N�������ϵ�$n�૵����˼������$n�鴤�˼��¾�վ��������\n", me, target); 
        target->animate(me, (int)me->query_skill("spells"));
        me->add("mana", -50);
        me->receive_damage("sen", 10);
        return 1;
}
       
