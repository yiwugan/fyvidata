// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "练功房");
        set("long", @LONG
这里是天龙寺弟子练功的房间，室内简单地陈列了一些练功必备
的物品，几个天龙寺僧人正在这里练功入定。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"lang1",
]));
        set("objects", ([
                __DIR__"npc/monk3" : 2,
       ]) );
        set("outdoors", "dali");
        set("coor/x",-960);
        set("coor/y",-820);
        set("coor/z",150);
        setup();
}