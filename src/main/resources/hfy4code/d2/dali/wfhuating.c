#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "����" NOR );
        set("long", @LONG
    ��������һ�Ե����ȣ�������һ��Ļ��������ڳ��軪��������
������������˼��������ΰ�����ĵ����ֱ���һ������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"wfchanglang",
  "north" : __DIR__"wfdating",

]));
        set("objects", ([
        __DIR__"npc/yahuan" : 2,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-750);
        set("coor/y",-710);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}