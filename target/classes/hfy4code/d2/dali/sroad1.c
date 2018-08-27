#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG "大理南街" NOR);
        set("long", @LONG
        眼前是一条笔直的大石路，路上青石平铺，通向大理国的皇宫。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"dalicenter",
  "south" : __DIR__"sroad2",
  "east" : __DIR__"pawn1",
  "west" : __DIR__"bank1",
]));
         set("objects", ([
         __DIR__"npc/fan1" : 1,
                         ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-800);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}