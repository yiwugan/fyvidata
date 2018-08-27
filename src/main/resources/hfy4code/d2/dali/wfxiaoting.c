#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "小亭" NOR );
        set("long", @LONG
    这里是王府一角的一个小亭，从这里可以看到远处的群山，
放眼但见山青水绿，天蓝云苍，夕阳橙黄，晚霞桃红，真是一个
纳凉赏景的好地方。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"wfhuayuan",
  "northwest" : __DIR__"wfchanglang",
  "south" : __DIR__"wfshufang",

]));
        set("objects", ([
        __DIR__"npc/yahuan" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-720);
        set("coor/y",-720);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}