// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{

        set("short", "移花小径");
        set("long", @LONG
走进这里.一阵阵扑鼻而来的花香不由得让你心
醉神迷.让你进来了都不想出去...........
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "south"     : __DIR__"xiaojing",
                 "north"     : __DIR__"xiaojing2",
        ]));
        set("coor/x",-165);
	set("coor/y",175);
	set("coor/z",30);
         setup();
}
