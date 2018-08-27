inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "老松树顶");
        set("long", @LONG
这是一棵千年古松，如一把巨伞撑在半空中。四周长着一些老藤，
山崖中裂开了一条大缝，好象能爬（ｃｌｉｍｂ）下去。只见左边山
崖上一条大瀑布如玉龙悬空，滚滚而下，倾入一座清澈异常的大湖之
中。
LONG
        );
        set("coor/x",-700);
        set("coor/y",-900);
        set("coor/z",140);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        me = this_player();
        if( arg == "down") 
        {
                message_vision("$N慢慢地往山谷下爬去。\n", me);
                me->move(__DIR__"gudi.c");
                return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}