// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{

        set("short", "�ƻ�С��");
        set("long", @LONG
�߽�����.һ�����˱Ƕ����Ļ��㲻�ɵ�������
������.��������˶������ȥ...........
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "south"     : __DIR__"xiaojing",
                 "north"     : __DIR__"xiaojing2",
        ]));
        set("coor/x",-165);
	set("coor/y",175);
	set("coor/z",30);
         setup();
}
