#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "正德殿" NOR);
        set("long", @LONG
这里是承德殿前的一个大殿，这里是给大臣上朝时休息用的。现在
已经散朝了，只有几个卫士在殿上执勤。经过前面的正殿，就到了皇宫
的中心承德殿。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"guangchang",
  "north" : __DIR__"zhengdian",

]));
        set("objects", ([
                __DIR__"npc/jinyi" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-640);
        set("coor/z",90);
        setup();
}