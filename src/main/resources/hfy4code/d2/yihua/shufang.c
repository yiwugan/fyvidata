//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "书房");
	set("long", @LONG
这是花无缺平日里休闲读书的地方.虽然乃一宫之主.
却总忘不了没日必定来读写一番.
LONG );
 	set("exits",([
	    "north" : __DIR__"woshi",
	    "west" : __DIR__"dating",  				
	]));
        set("coor/x",-170);
	set("coor/y",225);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
