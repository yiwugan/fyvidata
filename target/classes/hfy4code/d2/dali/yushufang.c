#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "御书房" NOR);
        set("long", @LONG
这里是皇宫的御书房。大理国人人信奉佛教，书房内也不乏
佛家经典。由于大理段氏世代习武，这里也收藏了大理段氏的不
少武功秘要。
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"guangchang1",
]));
        set("objects", ([
                __DIR__"npc/weishi" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-210);
        set("coor/y",330);
        set("coor/z",70);
        setup();
}