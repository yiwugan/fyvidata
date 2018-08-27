#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",YEL "大理街道" NOR );
        set("long", @LONG
    眼前是一条笔直的大街，街上青石平铺，极为宽敞。前面是一座
大府第，府门前两面大旗，旗上分别绣的是「镇南」、「保国」两字，
府额上写的是「镇南王府」。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"gnroad2",
  "east" : __DIR__"wfdoor",

]));
        set("outdoors", "dali");
        set("coor/x",-790);
        set("coor/y",-700);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}