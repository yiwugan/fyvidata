#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "花厅" NOR );
        set("long", @LONG
    穿过大厅一旁的走廊，来到了一侧的花厅。厅内陈设华美，雕梁
画栋，极穷巧思，比诸雄伟豪华的殿堂又别有一番气象。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"wfchanglang",
  "north" : __DIR__"wfdating",

]));
        set("objects", ([
        __DIR__"npc/yahuan" : 2,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-750);
        set("coor/y",-710);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}