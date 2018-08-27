inherit ROOM;
void create()
{
        set("short", "飘香茶庄");
        set("long", @LONG
这里是大理城里的有名的茶庄，各种远近驰名的茶叶在这里都能买到。来到
大理不到这里品品茶，真是枉来大理。在这里你也可以品尝到大理的特色小吃
“过桥米线”。浓郁的茶香和特色的菜肴让你走不动道。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wroad1",
]));
        set("outdoors", "dali");
        set("objects", ([
         "d/dali/npc/waiter1.c" : 1,
                        ]) );

        set("coor/x",-850);
        set("coor/y",-740);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}
