//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "前殿");
	set("long", @LONG
这是一间很大的客厅.非常的大.四周墙壁挂满了
美女的画.据说是每一代移花宫主传位后所留.可
见移花宫在江湖中乃又一流转悠久的门派.
LONG );
 	set("exits",([
	    "north" : __DIR__"dating",
	    "east" : __DIR__"chufang",  				    "south" : __DIR__"damen",
	]));
        set("coor/x",-180);
	set("coor/y",220);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
