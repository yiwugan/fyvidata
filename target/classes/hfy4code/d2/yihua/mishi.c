#include <room.h>
inherit ROOM;
void create()
{
        set("short", "思过房");
	set("long", @LONG
里面摆放着一张香桌.香桌四周坐着当年呲诧江湖的十大恶人.
如今在这里忏悔思过.噫，今天怎么一个人都不见了？
LONG );
 	set("exits",([
            "west" :"u/yihua/wushi",                            
	]));
          set("objects", ([
/*  14                  __DIR__"npc/tujiao" : 1,
                __DIR__"npc/ouyangding" : 1,
               __DIR__"npc/hahaer" : 1,
               __DIR__"npc/yinjiuyou" : 1,
               __DIR__"npc/tiezhan" : 1,
               __DIR__"npc/ouyangdang" : 1,
               __DIR__"npc/dusha" : 1,
               __DIR__"npc/xiaomimi" : 1,
               __DIR__"npc/sanguang" : 1,
               __DIR__"npc/lidazui" : 1,
 24                 __DIR__"npc/baikaixin" : 1,   */
       ]) );
	set("no_magic", 1);
	setup();
	create_door("west", "窄门", "east", DOOR_CLOSED);
}
