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
                "southup"     : "/d/yihua/juebi",
                 "north"     : __DIR__"xiaojing1",
        ]));
        set("coor/x",-165);
	set("coor/y",170);
	set("coor/z",30);
         setup();
}
