#include <room.h>
inherit ROOM;
void create()
{
  set("short","藏经阁");
  set("long",@LONG
这里只有书，各式各样的经书．．．。还有一个老和尚面向里坐着。
LONG
  );
  set("exits",([
         "south":__DIR__"lang2.c",
               ]));
          set("objects", ([
                __DIR__"npc/kurong" : 1, //天龙寺长老 枯荣大师(Ku rong)
       ]) );
        set("outdoors", "dali");
        set("coor/x",-980);
        set("coor/y",-810);
        set("coor/z",150);
        setup();
        create_door("south", "石门", "north", DOOR_CLOSED);
}