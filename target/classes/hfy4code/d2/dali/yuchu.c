#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "御厨房" NOR);
        set("long", @LONG
这里是展中省所属的御厨，厨中烛火通明，几个厨子正忙着为
宫中准备晚餐。看着满屋的满味佳肴，你望着不由得直流口水。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jiamingdian",

]));
//        set("objects", ([
//                __DIR__"npc/master_20" : 1,
//       ]) );
        set("outdoors","dali");
        set("coor/x",-830);
        set("coor/y",-650);
        set("coor/z",80);
        setup();
}