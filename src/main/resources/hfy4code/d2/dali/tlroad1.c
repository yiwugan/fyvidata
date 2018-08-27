inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条上山小路，是由大理城往天龙寺的山路。路边密林覆盖。东
北是大理城西门。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"wdoor",
  "southwest" : __DIR__"tlroad2",
]));
//        set("objects", ([
//        __DIR__"npc/trader" : 3,
//                        ]) );
        set("outdoors", "dali");
        set("coor/x",-920);
        set("coor/y",-780);
        set("coor/z",100);
        setup();
        replace_program(ROOM);

}