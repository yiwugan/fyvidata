 // Copyright (C) 2001, by neon
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int assign_deliver();
void create()
{
        set_name("���������ϰ�", ({ "flowerowner" }) );
        set("gender", "Ů��" );
        set("age", 35);
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",16);
        set("inquiry", ([
                "�ͻ�" : (: assign_deliver :),
                "songhua" : (: assign_deliver :),
                "deliver" : (: assign_deliver :),
        ]));
        setup();
}
int assign_deliver()
{
        object me , obj;
        me = this_player();
        if( !me->query("delivering")) {
        obj = new(__DIR__"obj/flower");
        message_vision("$Nsend flower $n��\n",this_object(), me);
        obj->move(me);
        me->set("delivering",1);
        return 1;
        }
        return 0;
} 
void reset()
{
delete("assigning");
}      
