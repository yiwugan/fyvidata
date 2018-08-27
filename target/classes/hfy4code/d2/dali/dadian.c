// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "天龙寺大殿");
        set("long", @LONG
这里是天龙寺众僧早晚课之处，殿内陈设极为简单，佛像前摆着一
个供桌，桌上的香炉中插着几柱香。地上摆着六个蒲团。有一个小和尚
正在打扫。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"tldoor",
  "west" : __DIR__"houdian",
]));
        set("objects", ([
                __DIR__"npc/bencan" : 1, //天龙寺高僧 本参(Ben can)
                __DIR__"npc/monk1" : 1,
                __DIR__"npc/pker" : 1,
       ]) );
//        set("outdoors", "dali");
        set("coor/x",-960);
        set("coor/y",-800);
        set("coor/z",150);
        setup();
}
