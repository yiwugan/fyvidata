#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "СԺ");
    set("long", @LONG
��
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"grassland",
        "north" : __DIR__"garden",
        ]));
        set("outdoors","neon_playground");
        set("coor/x",-20);
        set("coor/y",30040);
        set("coor/z",0);
        setup();
}     
