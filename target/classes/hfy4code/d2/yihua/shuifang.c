//yixin@bft.c
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "寝室");
	set("long", @LONG
这是移花宫弟子平日睡觉的地方.里面摆放着十四
张玉石做的床.比起宫主的要高档昂贵的多.可见宫
主对本门弟子的关心之微.
LONG );
 	set("exits",([
	    "south" : __DIR__"chang",  				
	]));
        set("coor/x",-190);
	set("coor/y",227);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
}
