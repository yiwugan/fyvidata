#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIR "司马衙门" NOR );
        set("long", @LONG
    这里是大理的司马衙门。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"gnroad2",
]));
        set("objects", ([
       __DIR__"npc/fan" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-810);
        set("coor/y",-700);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}