#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "王府花园" NOR );
        set("long", @LONG
    这里是镇南王府的后花园，这里虽然规模远较皇宫的御花园
小，但这里的每品茶花都显然是经过精心培育，款款惹人喜爱。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"wfxiaoting",

]));
        set("objects", ([
        __DIR__"npc/yahuan" : 1,
        __DIR__"npc/jiading" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-710);
        set("coor/y",-720);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}