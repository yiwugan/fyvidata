//yixin@bft.c
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·����ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ���
���Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£���������������
�ף���ʱ���˺�����������Ҫ��Хһ����
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "eastup"    : __DIR__"feiyun",
                "southdown"    : __DIR__"shanlu1",
        ]));
        set("coor/x",-180);
	set("coor/y",165);
	set("coor/z",30);
        setup();
}
