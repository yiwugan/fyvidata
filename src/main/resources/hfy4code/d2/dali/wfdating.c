#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "镇南王府大厅" NOR );
        set("long", @LONG
    走过长长的白玉阶，来到王府大厅。只见正中一块牌匾，写着
「邦国柱石」四个大字，下首署着「丁卯御笔」四个小字。楹柱中
堂挂满了字画，一时也看不了许多。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"wfhuating",
  "westdown" : __DIR__"wfdoor",

]));
        set("objects", ([
        __DIR__"npc/jiading" : 2,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-750);
        set("coor/y",-700);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}