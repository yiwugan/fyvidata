#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HBMAG"大理西门" NOR);
        set("long", @LONG
    这里是大理的西城门，出城就是大大小小的山群。这一带
行人不多。
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"tlroad1",
  "east" : __DIR__"wroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-900);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);


}