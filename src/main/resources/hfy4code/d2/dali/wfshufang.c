#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "书房" NOR );
        set("long", @LONG
    书房中琳琅满目，全是诗书典籍，几上桌上摆着许多铜器玉器，
看来尽是古物。壁上挂着一幅水墨画，画的却是一位宫装少女，甚是
逼真传神。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"wfxiaoting",

]));
        set("objects", ([
        __DIR__"npc/duanzhch" : 1,
                        ]) );
         set("outdoors", "dali");
        set("coor/x",-720);
        set("coor/y",-730);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}