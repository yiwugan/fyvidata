#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "勤政殿" NOR);
        set("long", @LONG
勤政殿是保定帝的寝宫所在地，殿内珠帘低垂，红烛高照，几
个宫装少女正在收拾房间。穿过大殿，后进就是几间小殿，那就是
皇帝休息的地方了。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"xiaoyuan",
  "west" : __DIR__"qingong",
  "east" : __DIR__"hglang2",
]));
        set("objects", ([
                __DIR__"npc/gongnv" : 1,
                __DIR__"npc/xtaijian" : 1,
       ]) );
        set("outdoors","dali");
        set("coor/x",-820);
        set("coor/y",-630);
        set("coor/z",90);
        setup();
}