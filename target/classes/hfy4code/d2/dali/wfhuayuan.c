#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "������԰" NOR );
        set("long", @LONG
    ���������������ĺ�԰��������Ȼ��ģԶ�ϻʹ�������԰
С���������ÿƷ�軨����Ȼ�Ǿ��������������������ϲ����
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"wfxiaoting",

]));
        set("objects", ([
        __DIR__"npc/yahuan" : 1,
        __DIR__"npc/jiading" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-710);
        set("coor/y",-720);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}