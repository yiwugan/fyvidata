inherit ROOM;
void create()
{
        set("short", "峭壁下面");
        set("long", @LONG
眼前是一处峭壁，来时的山洞也找不到了。向东有一条
小路。南面的峭壁直冲云霄。西边有一片竹林，从竹林那边
不时传来女子的叹息声。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"zhulin",
  "east" : __DIR__"shanroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-710);
        set("coor/y",-900);
        set("coor/z",80);
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
        me->move(__DIR__"qiaobi");
        message_vision("$N顺着峭壁爬了上来。\n", me);
        }
        return 1;
}