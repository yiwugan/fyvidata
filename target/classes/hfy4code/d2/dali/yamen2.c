#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",RED "˾������" NOR );
        set("long", @LONG
    �����Ǵ����˾�����š�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"gnroad1",
]));
        set("objects", ([
        __DIR__"npc/ba" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-790);
        set("coor/y",-730);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}