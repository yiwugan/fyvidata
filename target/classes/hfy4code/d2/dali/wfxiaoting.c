#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "Сͤ" NOR );
        set("long", @LONG
    ����������һ�ǵ�һ��Сͤ����������Կ���Զ����Ⱥɽ��
���۵���ɽ��ˮ�̣������Ʋԣ�Ϧ���Ȼƣ���ϼ�Һ죬����һ��
�����;��ĺõط���
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"wfhuayuan",
  "northwest" : __DIR__"wfchanglang",
  "south" : __DIR__"wfshufang",

]));
        set("objects", ([
        __DIR__"npc/yahuan" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-720);
        set("coor/y",-720);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}