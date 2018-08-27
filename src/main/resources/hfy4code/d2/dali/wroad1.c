#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG "大理西街" NOR);
        set("long", @LONG
    你走在大理城的西大街上，大街上青石平铺。大理城内人烟稠
密，市肆繁华，颇有一派世外桃园的景象，往道路的南面看，你会发现
有一家大理棋院，北面有家品香茶庄，走在这条街道上，一股浓郁的茶香把
你重重包围。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"dalicenter",
  "west" : __DIR__"wroad2",
  "north" :__DIR__"chazhuang",
  "south" :__DIR__"qiyuan",
]));
        set("outdoors", "dali");
        set("coor/x",-850);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}