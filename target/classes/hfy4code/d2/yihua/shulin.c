//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "树林");
	set("long", @LONG
终于穿出了小径，眼前是一望无际的树林，没有路标，也没
有一个行人，天显得很高，远山披雪，苍鹰翱翔，好一派不
同于中土的异域风光。不远处，几只白骨散落地上,好似人的尸骨?
走在这茫茫树林之中，你似乎迷路了。
LONG );
 	set("exits",([
		      "east" : __DIR__"xiaojing3",
		      "west" : __DIR__"shulin1",	
		      "north" : __DIR__"shulin",
                      "south" : __DIR__"shulin",  				
	]));
        set("coor/x",-165);
	set("coor/y",190);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
