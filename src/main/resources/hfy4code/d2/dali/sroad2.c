#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG "大理南街" NOR);
        set("long", @LONG
        眼前是一条笔直的大石路，路上青石平铺，向北通向大理国的皇宫。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"sroad1",
  "east" : __DIR__"huadian",
  "west" : __DIR__"chayuan",
  "south" : __DIR__"sdoor",
]));
        set("objects", ([
        __DIR__"npc/dtz" : 3,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-830);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}