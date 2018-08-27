 inherit ROOM;
void create()
{
        set("short", "仙人洞");
        set("long", @LONG
进入石洞，只见佳木茏葱，奇花烂熳，一带清流，从花木深处
泻于石隙之下。俯而视之，但见清溪泻玉，石笋穿云，白石为栏，
环抱池沼，石桥三港，兽面吞吐。
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"palace_front",
  "southdown" : AREA_TIEFLAG"troad0",
]));
        set("objects", ([
               __DIR__"npc/master2" : 1,
       ]) );
        set("valid_startroom", 1);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",40);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",40);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}   
