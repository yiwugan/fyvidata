#include <room.h>
inherit ROOM;
void create()
{
  set("short","主持院");
  set("long",@LONG
簇拥在禅房之间的为历代方丈的居所。天龙寺是大理皇家寺庙，
在这里出家的都是大理段氏的皇族。
LONG
  );
  set("exits",([
         "north":__DIR__"lang1.c",
               ]));
          set("objects", ([
                __DIR__"npc/benyin" : 1, //天龙寺方丈 本因(Ben yin)
       ]) );
//  set("valid_startroom", 1);
//        set("outdoors", "dali");
        set("coor/x",-970);
        set("coor/y",-830);
        set("coor/z",150);
        setup();
}
