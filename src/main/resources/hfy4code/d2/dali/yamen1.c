#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",RED "司徒衙门" NOR );
        set("long", @LONG
    这里是大理的司徒衙门。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"gnroad1",
]));
        set("objects", ([
        __DIR__"npc/hua" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-810);
        set("coor/y",-730);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}
