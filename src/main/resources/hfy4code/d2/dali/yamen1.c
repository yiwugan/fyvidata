#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",RED "˾ͽ����" NOR );
        set("long", @LONG
    �����Ǵ����˾ͽ���š�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"gnroad1",
]));
        set("objects", ([
        __DIR__"npc/hua" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-810);
        set("coor/y",-730);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}
