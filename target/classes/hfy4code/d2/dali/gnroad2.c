#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIY "皇宫大道" NOR );
        set("long", @LONG
    眼前是一条笔直的大石路，路上青石平铺，路的尽头耸立着无
数黄瓦宫殿，夕阳照在琉璃瓦上，金碧辉煌，令人目为之炫。向东
的一条大路就通向大理国镇南王府。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"estreet",
  "south" : __DIR__"gnroad1",
  "west" : __DIR__"yamen3",
  "north" : __DIR__"paifang",

]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-700);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}