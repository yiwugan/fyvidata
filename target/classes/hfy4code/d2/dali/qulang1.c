#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",CYN "曲廊" NOR);
        set("long", @LONG
这是正殿后面的一条长长的曲廊，曲廊绕过两边宫殿，下面是
一个小湖。走在桥上，但觉凉风拂体，远处传来阵阵流水声，随风
又送来阵阵花香，深宫庭院，竟然忽有山林野处意境。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"zhengdian",
  "northeast" : __DIR__"qulang2",

]));
        set("objects", ([
                __DIR__"npc/gongnv" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-610);
        set("coor/z",90);
        setup();
}