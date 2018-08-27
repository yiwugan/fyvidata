 inherit ROOM;
void create()
{
        set("short", "镖局货仓");
        set("long", @LONG
金狮镖局声誉如日中天，从未失镖。顾主的货物在这里堆积如山。镖局的伙计
们正在手忙脚乱的往镖车上装载货物。虽然每个伙计都已满头大汗，尽力而为，但
还是忙不过来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"goldlion",
]));
        set("objects", ([
        __DIR__"npc/huoji" : 2,
        __DIR__"npc/bad_huoji" : 1,
                        ]) ); 
        set("coor/x",10);
        set("coor/y",50);
        set("coor/z",0);
        set("coor/x",10);
        set("coor/y",50);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_work", "work");
}
int do_work(string arg)
{
        object ob;
        object me; 
        me = this_player(); 
message_vision("$N帮镖局的伙计往镖车上装载货物，真辛苦真累！！\n",me);
me->add("gin",-30);
me->add("sen",-30);
me->set("marks/金狮", time());
return 1;
}  
