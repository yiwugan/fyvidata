#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "������������" NOR );
        set("long", @LONG
    �߹������İ���ף���������������ֻ������һ�����ң�д��
�������ʯ���ĸ����֣��������š���î���ʡ��ĸ�С�֡������
�ù������ֻ���һʱҲ��������ࡣ
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"wfhuating",
  "westdown" : __DIR__"wfdoor",

]));
        set("objects", ([
        __DIR__"npc/jiading" : 2,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-750);
        set("coor/y",-700);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}