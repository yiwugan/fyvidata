inherit ROOM;

void create()
{
        set("short", "密林之中");
        set("long", @LONG
一片茂密的热带树(tree)林。树叶遮住了太阳，眼前朦朦胧胧的，看
不清方向，远处传来流水声。
LONG
        );
        set("exits", ([
                "north" : __DIR__"quan6",
                "south" : __DIR__"quan2",
                "east" : __DIR__"quan7",
                "west" : __DIR__"quan4",
        ]));


        set("item_desc", ([
                "tree": "这里的树(tree)很密，但你似乎可以绕开(around)它们。\n",
                "树": "这里的树(tree)很密，但你似乎可以绕开(around)它们。\n"

        ]) );
        set("outdoors", "dali");
        set("coor/x",-620);
        set("coor/y",-780);
        set("coor/z",80);
        setup();
//      replace_program(ROOM);

}
void init()
{
        add_action("do_push", "around");
}
int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要绕开什么？\n");
                return 1;
        }
        if( arg == "tree" || arg == "树")
        {
        me = this_player();
        message_vision("$N绕开南面的树，发现了一条向南的小路。\n", me);
        if(!me->query("m_success/蝴蝶泉"))
        {
                me->set("m_success/蝴蝶泉",1);
                me->add("score",100);

        }
//      if( !query("exits/south") ) {
        set("exits/south", __DIR__"hdquan");
        call_out("close_path", 5);
//      }
        return 1;
        }
        else
        {
                write("你不可以绕过"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"向南的小路消失了。\n",
                this_object() );
        set("exits/south", __DIR__"quan2");
//              delete("exits/south");
}
