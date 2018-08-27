inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条僻静的山间小路，极少有人迹，路边是又高又密的
杂草。东北是一片树林。
LONG
        );
        set("exits", ([ 
  "northeast" :  __DIR__"quan7",
  "southwest" :  __DIR__"shanroad2"
]));
        set("outdoors", "dali");
        set("coor/x",-650);
        set("coor/y",-840);
        set("coor/z",80);
        setup();
}