#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "��������" NOR);
        set("long", @LONG
    �����ڴ���ǵ�������ϣ��������ʯƽ�̡�����������̳�
�ܣ���������������һ��������԰�ľ�������·�����濴����ᷢ��
��һ�������̣����������Ĵ������������洫����������һ���������
��������ÿ�������ڣ���Ҫ���������㻹Ը��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"wroad1",
  "west" : __DIR__"wdoor",
  "south" : __DIR__"smithy",
  "north" : __DIR__"miao",
]));
        set("objects", ([
                __DIR__"npc/girl2" : 1,
                __DIR__"npc/man2" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-880);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}