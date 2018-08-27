inherit ROOM;

void create()
{
        set("short", "竹屋");
        set("long", @LONG
一个小竹屋，收拾得干净舒适，一个非常美丽的年轻女子坐
在窗前，满眼忧郁，不时发出一声声叹息。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhulin",
]));
   //     set("no_fight",1);
        set("no_magic",1);
        set("outdoor","dali");
        set("coor/x",0);
        set("coor/y",-450);
        set("coor/z",10);
        set("objects", ([
                __DIR__"npc/wangyuyan" : 1,
       ]) );
        setup();
}