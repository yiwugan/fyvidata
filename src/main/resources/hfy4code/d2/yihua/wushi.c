// Tie@fengyun
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���䳡");
	set("long", @LONG
LONG );
 	set("exits",([
	    "west" : __DIR__"houyuan",
	    	]));
         set("coor/x",-170);
	set("coor/y",230);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
}
