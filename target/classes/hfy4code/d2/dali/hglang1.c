#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIC "走廊" NOR);
        set("long", @LONG
    这里是练武场与嘉明殿之间的一条长廊，两旁玉柱雕栏衬得这条
白石铺成的小廊格外清净、雅致。长廊外是一个小池，池里游鱼晶莹
剔透，池中央一座假山上一条涓涓细流注入池中，好一幅山水田园图。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"guangchang",
  "west" : __DIR__"jiamingdian",
]));
//        set("objects", ([
//                __DIR__"npc/master_20" : 1,
//       ]) );
        set("outdoors","dali");
        set("coor/x",-810);
        set("coor/y",-650);
        set("coor/z",80);
        setup();
}