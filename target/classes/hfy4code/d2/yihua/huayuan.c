// Tie@fengyun
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Բ");
	set("long", @LONG
�ƻ���.����˼��.��Ȼ�Ǻ�ϲ�����ĵط�.�������ǻ�
�㿴���е�Ŀ��������.
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
	create_door("south", "խ��", "north", DOOR_CLOSED);
}
