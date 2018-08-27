inherit ROOM;
void create()
{
        set("short", "峭壁");
        set("long", @LONG
这是峭壁上一块伸出的大石，可以歇歇脚。
LONG
        );
        set("outdoors", "dali");
        set("coor/x",-710);
        set("coor/y",-900);
        set("coor/z",100);
        setup();
}
init()
{
add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object  me;
        int     mlvl;

        if(!arg || arg != "up") {
                write("你要往哪里爬？\n");
                return 1;
        }
        me = this_player();
        {       message_vision( "\n$N沿着峭壁慢慢地向上爬去。\n" , me);
                me->start_busy(4);
                call_out("fliping",4,me);
                me->stop_busy();
        }
        return 1;
}

int fliping(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"biding");
        message_vision("$N顺着峭壁爬了上来。\n", me);
        }
        return 1;
}