//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "地下密室");
	set("long", @LONG
由于当年一场恶战.燕大侠全身经脉震断.成为废人
如今燕南天就在这个密室中。
LONG );
        set("exits", ([ 
  "east" : __DIR__"dishi",
])); 
        set("objects",([
          "d/yihua/npc/yannantian":1
        ]) );
        set("coor/x",-190);
	set("coor/y",250);
	set("coor/z",20);
        set("no_magic",1);
        set("no_dazuo",1);
	setup();
        replace_program(ROOM);
}
