inherit ROOM;

void create()
{
        set("short", "山顶");
        set("long", @LONG
一条非常宽阔的大路，是由大理城往沉香镇的官道。这是一个小山的
山顶，仿佛看得到西南的大理城。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"qxroad2",
  "southwest" : __DIR__"ting",
]));
        set("outdoors", "dali");
        set("coor/x",-600);
        set("coor/y",-700);
        set("coor/z",100);
        setup();
        replace_program(ROOM);

}
