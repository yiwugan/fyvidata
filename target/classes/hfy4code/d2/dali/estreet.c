#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",YEL "����ֵ�" NOR );
        set("long", @LONG
    ��ǰ��һ����ֱ�Ĵ�֣�������ʯƽ�̣���Ϊ����ǰ����һ��
�󸮵ڣ�����ǰ������죬���Ϸֱ�����ǡ����ϡ��������������֣�
������д���ǡ�������������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"gnroad2",
  "east" : __DIR__"wfdoor",

]));
        set("outdoors", "dali");
        set("coor/x",-790);
        set("coor/y",-700);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}