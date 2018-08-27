//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "树林");
	set("long", @LONG
眼前是一望无际的树林，没有路标，也没有一个行人，天
显得很高，远山披雪，苍鹰翱翔，走在这茫茫林海之中，你似乎
迷路了。
LONG );
 	set("exits",([
	    "east" : __DIR__"shulin3",
	    "west" : __DIR__"shulin3",	
	    "north" : __DIR__"shulin4",
	    "south" : __DIR__"shulin2",  				
	]));
        set("coor/x",-175);
	set("coor/y",195);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
