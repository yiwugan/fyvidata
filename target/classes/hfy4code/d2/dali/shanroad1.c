inherit ROOM;

void create()
{
        set("short", "林荫小路");
        set("long", @LONG
这里已经是玉虚观的地界了，只见碎石铺成的小路，两旁绿
柳婆娑，山坡上的野花争奇斗艳。
LONG
        );
        set("exits", ([ 
  "northdown" :  __DIR__"shanroad",
  "south" : __DIR__"yxguan",
]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-950);
        set("coor/z",110);
        setup();
        replace_program(ROOM);

}