#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIY "�ʹ����" NOR );
        set("long", @LONG
    ��ǰ��һ����ֱ�Ĵ�ʯ·��·����ʯƽ�̣�·�ľ�ͷ��������
�����߹��Ϧ�������������ϣ���̻Իͣ�����ĿΪ֮�š�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"gnroad2",
  "east" : __DIR__"yamen2",
  "west" : __DIR__"yamen1",
  "south" : __DIR__"dalicenter",
]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-730);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}