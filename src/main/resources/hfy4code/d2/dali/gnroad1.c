#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIY "皇宫大道" NOR );
        set("long", @LONG
    眼前是一条笔直的大石路，路上青石平铺，路的尽头耸立着无
数黄瓦宫殿，夕阳照在琉璃瓦上，金碧辉煌，令人目为之炫。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"gnroad2",
  "east" : __DIR__"yamen2",
  "west" : __DIR__"yamen1",
  "south" : __DIR__"dalicenter",
]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-730);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}