#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",RED "司空衙门" NOR );
        set("long", @LONG
    这里是大理的司空衙门。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"gnroad1",
]));
        set("objects", ([
        __DIR__"npc/ba" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-790);
        set("coor/y",-730);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}