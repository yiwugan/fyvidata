#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "大理西街" NOR);
        set("long", @LONG
    你走在大理城的西大街上，大街上青石平铺。大理城内人烟稠
密，市肆繁华，颇有一派世外桃园的景象，往道路的南面看，你会发现
有一家铁匠铺，叮叮当当的打铁声音从里面传出，北面有一不大的土地
庙，大理人每逢过年过节，都要到这里烧香还愿。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"wroad1",
  "west" : __DIR__"wdoor",
  "south" : __DIR__"smithy",
  "north" : __DIR__"miao",
]));
        set("objects", ([
                __DIR__"npc/girl2" : 1,
                __DIR__"npc/man2" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-880);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}