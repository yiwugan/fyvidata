#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "长廊" NOR );
        set("long", @LONG
    一条弯弯曲曲的长廊通向王府的后院，白玉栏杆上是巧匠雕琢
的茶花图案，形态各异，几欲乱真。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"wfxiaoting",
  "west" : __DIR__"wfhuating",

]));
        set("outdoors", "dali");
        set("coor/x",-730);
        set("coor/y",-710);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}