//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "һ���ɾ���Сʯ��");
	set("long", @LONG
����һ���ܸɾ���Сʯ��.���������ƻ���.
LONG );
 	set("exits",([
	    "north" : __DIR__"damen",
	    "south" : __DIR__"shidao2",  				
	]));
        set("coor/x",-180);
	set("coor/y",210);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
