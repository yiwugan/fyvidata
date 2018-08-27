 // invocation.c
inherit SSERVER;
#define MAX_GUARD 4
int cast(object me, object target)
{
        object soldier;
        int     spells,lvl; 
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n");
                    
//      if(me->query_temp("timer/invocation")+2>time())
//              return notify_fail("( ����һ��������û����ɣ����������ġ�)\n"); 
        spells = me->query_skill("spells");
        if(me->query_skill("necromancy",1) < 20 )
                return notify_fail("��ķ��������ߣ�\n"); 
        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в����ٻ��콫��\n");
        if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("���Ѿ��ٻ�̫����������ˣ�\n"); 
        lvl=me->query_skill("necromancy",1); 
        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ��������ˣ�\n");
        if( (int)me->query("sen") < 60 )
                return notify_fail("��ľ����޷����У�\n"); 
        message_vision("$N�૵����˼������\n", me); 
        if (lvl<130) {
                me->add("mana", -50);
                me->receive_damage("sen", 30);
        } else {
                me->add("mana", -50-(lvl-130));
                me->receive_damage("sen", 30+(lvl-130));
        }
        
        if (me->query("mana")<0) me->set("mana",0); 
        if( random(me->query("max_mana")) < 100 ) {
                message("vision", "����ʲ��Ҳû�з�����\n", environment(me));
                return 1;
        } 
        seteuid(getuid());
        if( random(spells) > (spells/2))
           soldier = new("/obj/npc/heaven_soldier");
        else
                soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        spells=spells/5*4;
        if (spells>260) spells=260;     
        soldier->invocation(me, spells);
        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
//      me->set_temp("timer/invocation",time());
        if (me->query_temp("max_guard")>1) me->start_busy(1);
        return 1;
}
