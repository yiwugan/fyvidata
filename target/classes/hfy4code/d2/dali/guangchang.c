#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIB "广场" NOR);
        set("long", @LONG
    这里是正德殿前的一个广场，四面种着一些茶花，中间是一大
块空地，保定帝经常来这里和宫中的侍卫一起较技。广场中央的几
个铜人就是平时练功所用。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"lizhengdoor",
  "west" : __DIR__"hglang1",
  "northup" : __DIR__"zhengdedian"
]));
        set("objects", ([
                __DIR__"npc/leader" : 1,
                __DIR__"npc/guard" : 4,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-650);
        set("coor/z",80);
        setup();
}