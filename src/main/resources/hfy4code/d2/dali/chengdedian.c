#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "承德殿" NOR);
        set("long", @LONG
这里就是大理国的金鸾宝殿，大理国中的朝政要事全是在这里
处理。殿内陈设华丽，镌镂龙凤飞镶之状，雄伟壮丽，金碧生辉。
正中朝南的龙椅上坐着大理国当今皇帝保定帝。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"zhengdian",
]));
        set("objects", ([
                __DIR__"npc/duanzhm" : 1,
                __DIR__"npc/jinyi" : 2,
                __DIR__"npc/xtaijian" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-620);
        set("coor/z",100);
        setup();

}