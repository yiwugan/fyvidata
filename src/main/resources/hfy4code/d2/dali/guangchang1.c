#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIB "广场" NOR);
        set("long", @LONG
这里是御书房前的一大片广场。皇帝散朝后经常要来书房看
书，因此这里的侍卫戒备禁严，一点也不敢大意。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"zhengdian",
  "eastup" : __DIR__"yushufang",
]));
        set("objects", ([
                __DIR__"npc/jinyi" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-210);
        set("coor/y",330);
        set("coor/z",70);
        setup();
}