//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "һ���ɾ���Сʯ��");
	set("long", @LONG
����һ���ܸɾ���Сʯ��.���������ƻ���.
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
