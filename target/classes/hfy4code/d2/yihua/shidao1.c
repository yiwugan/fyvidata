//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "一条干净的小石道");
	set("long", @LONG
这是一条很干净的小石道.往北就是移花宫.
LONG );
 	set("exits",([
	    "north" : __DIR__"shidao2",
	    "south" : __DIR__"shidao",  				
	]));
         set("coor/x",-180);
	set("coor/y",202);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
