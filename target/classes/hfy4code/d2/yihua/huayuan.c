// Tie@fengyun
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "后花圆");
	set("long", @LONG
移花宫.故名思意.当然是很喜欢花的地方.到处都是花
你看的有点目不节狭了.
LONG );
 	set("exits",([
	    "southwest" : __DIR__"huacong",
            "southeast" : __DIR__"huacong",
            "northwest" : __DIR__"huacong",
            "northeast" : __DIR__"huacong",
            "south" : __DIR__"houyuan",
            "north" : __DIR__"huacong",
            "west" : __DIR__"huacong2",
	    "east" : __DIR__"huacong1",  
        ]));
        set("coor/x",-180);
	set("coor/y",240);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	create_door("south", "窄门", "north", DOOR_CLOSED);
}
