#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "嘉明殿" NOR);
        set("long", @LONG
嘉明殿是大理皇宫供进御膳的所在，与寝宫所在的勤政殿相邻。
四周禁卫亲从、近侍中贵，提警得甚是禁严。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"hglang1",
  "west" : __DIR__"yuchu",
  "north" : __DIR__"xiaoyuan",

]));
        set("objects", ([
                __DIR__"npc/leader" : 1,
                __DIR__"npc/guard" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-820);
        set("coor/y",-650);
        set("coor/z",80);
        setup();
}