#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG "大理东街" NOR);
        set("long", @LONG
眼前是一条用五色彩石铺成的大道，道路笔直。往北通向大理城北门，往南
就到了大理城的中心。路的两旁种满了珍奇的花草。透过一株株开的正艳的茶花
向两旁看去，你会发现路的南面有一家兵器铺，路的北面有一家迎宾酒家。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"dalicenter",
  "east" : __DIR__"eroad2",
  "south" :__DIR__"bingqipu",
  "north" :__DIR__"jiujia",

]));
        set("objects", ([
                __DIR__"npc/girl" : 1,
                __DIR__"npc/man" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-750);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}