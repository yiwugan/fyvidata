 // forage.c
// Created by Silencer 
#include <ansi.h> 
int exert(object me, object target)
{
        int lvl;
        object fruit;
        if (me->query("class")!="wolfmount")
                return notify_fail("ֻ����ɽ���Ӳ�����Ч�زɼ�ʳ�\n");
        if (environment(me) && !environment(me)->query("outdoors"))
                return notify_fail("��ֻ��������ɼ�ʳ�\n");
        if (me->query_skill("wolf-force",1)<50)
                return notify_fail("��������ķ�̫���ˡ�\n");
        if( me->is_fighting())
                return notify_fail(HIR "ս�����޷����Ĳɼ�ʳ�\n"NOR);
        
        if( (int)me->query("timer/forage")+20 > time() )
                return notify_fail("��̫���ˣ�����Ϣһ�����˵�ɡ�\n");
        
        me->set("timer/forage",time());
        message_vision("$N�Ĵ�������Ѱ�ҿ��Թ���֮�\n",me);
        
        lvl= me->query_skill("wolf-force",1);
        if (random(lvl)<25)
                return notify_fail("��ʲôҲû�ҵ�����æ����һ����\n");
        seteuid(getuid());
        fruit= new("/obj/specials/wolfitem/wolf_fruit");
        fruit->move(me);
        tell_object(me,"���ҵ���һЩҰ����\n");
        return 1;
}   
