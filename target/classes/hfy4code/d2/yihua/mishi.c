#include <room.h>
inherit ROOM;
void create()
{
        set("short", "˼����");
	set("long", @LONG
����ڷ���һ������.�����������ŵ����ڲｭ����ʮ�����.
������������˼��.�棬������ôһ���˶������ˣ�
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
	create_door("west", "խ��", "east", DOOR_CLOSED);
}
