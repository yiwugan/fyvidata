//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "移花宫大厅");
	set("long", @LONG
到处充满香气.到处都是杀机.这里非常的安静
只有一个人坐在这里.这个人不停的洗着自己的
手.不停的洗着.........
LONG );
 	set("exits",([
	    "north" : __DIR__"houyuan",
	    "east" : __DIR__"shufang",  				    "west" : __DIR__"chang",
            "south" : __DIR__"qiandian",
	]));
        set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
        set("coor/x",-180);
	set("coor/y",225);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
