#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "����" NOR );
        set("long", @LONG
    һ�����������ĳ���ͨ�������ĺ�Ժ���������������ɽ�����
�Ĳ軨ͼ������̬���죬�������档
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"wfxiaoting",
  "west" : __DIR__"wfhuating",

]));
        set("outdoors", "dali");
        set("coor/x",-730);
        set("coor/y",-710);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}