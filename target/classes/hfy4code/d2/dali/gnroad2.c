#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIY "�ʹ����" NOR );
        set("long", @LONG
    ��ǰ��һ����ֱ�Ĵ�ʯ·��·����ʯƽ�̣�·�ľ�ͷ��������
�����߹��Ϧ�������������ϣ���̻Իͣ�����ĿΪ֮�š���
��һ����·��ͨ����������������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"estreet",
  "south" : __DIR__"gnroad1",
  "west" : __DIR__"yamen3",
  "north" : __DIR__"paifang",

]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-700);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}