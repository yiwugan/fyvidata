inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条上山小路，是由大理城往天龙寺的山路。路边密林覆盖。西
面是天龙寺山门。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"tlroad1",
  "westup" : __DIR__"tldoor",
]));
//        set("objects", ([
//        __DIR__"npc/trader" : 3,
//                        ]) );
        set("outdoors", "dali");
        set("coor/x",-940);
        set("coor/y",-800);
        set("coor/z",100);
        setup();
        replace_program(ROOM);

}