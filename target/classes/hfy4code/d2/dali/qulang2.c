#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",CYN "曲廊" NOR);
        set("long", @LONG
这是小湖上的一条长长的曲廊，曲廊绕过两边宫殿。走在桥上，
但觉凉风拂体，远处传来阵阵流水声，随风又送来阵阵花香，深宫
庭院，竟然忽有山林野处意境。
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"qulang1",
  "east" : __DIR__"yuhuayuan",
]));
//        set("objects", ([
//                __DIR__"npc/master_20" : 1,
//       ]) );
        set("outdoors","dali");
        set("coor/x",-790);
        set("coor/y",-600);
        set("coor/z",80);
        setup();
}