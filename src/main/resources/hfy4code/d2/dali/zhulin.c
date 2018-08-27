inherit ROOM;

void create()
{
        set("short", "竹林之中");
        set("long", @LONG
这是一片茂密的竹林，眼前满是翠绿的竹子，脚下软绵绵的。
西面有一个用住栅栏围起的院子，栅栏门开着，里面有一间竹屋。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhuwu",
  "east" : __DIR__"shanjiao",
]));
        set("outdoor","dali");
        set("coor/x",0);
        set("coor/y",-450);
        set("coor/z",10);
        setup();
}