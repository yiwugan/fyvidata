inherit ROOM;
string look_CAI();
void create()
{
    set("short", "莲花池");
    set("long", @LONG
这里是移花宫内的一个莲花池，池内开满了莲花，忍
不住想伸手去摘一朵。不过这个池内传言淹死过无数的人！
LONG
    );
    set("exits", ([
        "east" : __DIR__"xiaojing2",
    ]));
    set("item_desc",([
        "CAI"       :   (: look_CAI :),
    ]));
    setup();
}
void init()
{
    add_action("do_CAI","CAI");
}
int do_CAI(string arg)
{
    object me, killer;
    int i, ging_cost, qi_cost;
    me = this_player();
    i = (int)me->query_skill("dodge", 0) + random(200);
    ging_cost = 600 / (int)me->query_int();
    qi_cost = 500 / (int)me->query_int();
    if(((int)me->query("gin") < ging_cost) || ((int)me->query("kee") < qi_cost))
        i = 0;
    message_vision("$N纵身跳上荷叶，伏身去采了一朵莲花。\n", me);
    me->move(__DIR__"lianhuachi");
    reset_eval_cost();
    message_vision("只听『砰』地一声$N从莲花池中跳了出来。\n", me);
    if ( i < 50)
    {
        killer = new(("/d/yihua/npc") + "/lianxing");
         me->set_temp("last_damage_from",killer);
                me->die();
        destruct(killer);
    }
    else{ if( i < 125)
        me->unconcious();
    else {
        message_vision("$N已稳稳地站在池边。\n", me);
                if (me->query_skill("dodge", 1)<150)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
              else me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/6);
        me->receive_damage("gin", ging_cost );
        me->receive_damage("kee", qi_cost );
        me->set_temp("die_for","采莲淹");
        me->delete_temp("last_damage_from");
    }
   }
    return 1;
}
string look_chi()
{
    return  "这里是莲花池的池边，你望过去是一片莲花池，你忍不住想去池中采朵莲花.\n";
}