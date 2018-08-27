inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是通往大理后山的一条僻静的小路，平时少有人迹，只有
几个去玉虚观进香的女香客。
LONG
        );
        set("exits", ([ 
  "north" :  __DIR__"sdoor",
  "southup" : __DIR__"shanroad1",
//  "eastsouth" : __DIR__"dali/???",
]));
        set("objects", ([
        __DIR__"npc/girl1" : 1,
        __DIR__"npc/girl2" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-900);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}