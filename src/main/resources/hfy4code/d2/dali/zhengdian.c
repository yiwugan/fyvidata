#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "正殿" NOR);
        set("long", @LONG
这里是承德殿前的一间正殿。这里是朝臣上朝必由之路，因此
殿内甲士林立，戒备森严。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"guangchang1",
  "south" : __DIR__"zhengdedian",
  "west" : __DIR__"hglang2",
  "north" : __DIR__"qulang1",
  "northup" : __DIR__"chengdedian",

]));
        set("objects", ([
                __DIR__"npc/weishi" : 2,
                __DIR__"npc/jinyi" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-630);
        set("coor/z",90);
        setup();

}