#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIG "小园" NOR);
        set("long", @LONG
这里是勤政殿前的一个小园，适逢茶花盛开的季节，园中的茶花
争奇斗艳，竞相开放。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"jiamingdian",
  "northup" : __DIR__"qinzhengdian",

]));
//        set("objects", ([
//                __DIR__"npc/master_20" : 1,
//       ]) );
        set("outdoors","dali");
        set("coor/x",-820);
        set("coor/y",-640);
        set("coor/z",80);
        setup();
}