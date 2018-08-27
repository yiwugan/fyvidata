inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
一条非常宽阔的大路，是由大理城往沉香镇的官道。地势越来
越高，路两边隐约可见连绵不绝的山脉。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"qxroad1",
  "southwest" : __DIR__"qxroad",
]));
        set("objects", ([
        __DIR__"npc/girl" : 2,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-550);
        set("coor/y",-650);
        set("coor/z",50);
        setup();
        replace_program(ROOM);

}