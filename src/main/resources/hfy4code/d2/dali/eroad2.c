#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG "大理东街" NOR);
        set("long", @LONG
眼前是一条用五色彩石铺成的大道，道路笔直。往北通向大理城北门，往南
就到了大理城的中心。路的两旁种满了珍奇的花草。透过一株株开的正艳的茶花
向两旁看去，你会发现路的南面有一家杂货铺，路的北面有一家成衣铺。

LONG
        );
        set("exits", ([ 
  "east" : __DIR__"edoor",
  "west" : __DIR__"eroad1",
  "south" :__DIR__"zahuopu",
  "north" :__DIR__"chengyipu",
]));
        set("objects", ([
                __DIR__"npc/girl1" : 1,
                __DIR__"npc/man1" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-720);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}