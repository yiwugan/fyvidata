inherit ROOM;

void create()
{
        set("short", "山谷");
        set("long", @LONG
山谷间有一条僻静的小路，极少有人迹，路边是又高又密的
杂草。一条向东北的路也不知通向哪。
LONG
        );
        set("exits", ([ 
  "northeast" :  __DIR__"shanroad2"
]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-900);
        set("coor/z",90);
        setup();
}