//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "花丛中");
	set("long", @LONG
花.到处都是花.四周全是花.你不禁开始后悔来到
这种地方.又迷路了.你看的有点目不节狭了.
LONG );
 	set("exits",([
	    "southwest" : __DIR__"huacong",
            "southeast" : __DIR__"huacong",
            "northwest" : __DIR__"huacong",
            "northeast" : __DIR__"huacong",
            "south" : __DIR__"huacong",
            "north" : __DIR__"huacong",
            "west" : __DIR__"huacong",
            "east" : __DIR__"congwai",                                  
	]));
        set("coor/x",-190);
	set("coor/y",240);
	set("coor/z",30); 
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
