// Tie@fengyun
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "∫Û‘∫");
        set("long", @LONG

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dating",
  "east" : __DIR__"wushi",
  "north" : __DIR__"huayuan",
]));

        set("outdoors", "yihua");
        set("coor/x",-180);
	set("coor/y",230);
	set("coor/z",30);
	setup();
       create_door("north", "’≠√≈", "south", DOOR_CLOSED);

}
