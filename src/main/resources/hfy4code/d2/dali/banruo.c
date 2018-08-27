// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "般若殿");
        set("long", @LONG
这里是天龙寺众僧静修之处，殿内陈设极为简单，佛像前摆着一
个供桌，桌上的供品应有尽有。地上摆着六个蒲团。由于是静修之处，
所以这里特别的肃静。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"houdian",
  "south" : __DIR__"lang1",
]));
        set("objects", ([
                __DIR__"npc/benchen" : 1, //天龙寺高僧 本尘(Ben chen)
                __DIR__"npc/monk5" : 2,
       ]) );
//        set("outdoors", "dali");
        set("coor/x",-970);
        set("coor/y",-810);
        set("coor/z",150);
        setup();
}