#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "������������" NOR );
        set("long", @LONG
������ǰ��ֻ�����Ĵ���֮ǰ������˸��ʣ���ͷ��������
����ʯʨ���������ԣ�һ�Ű����ʯֱͨ��ǰ�������ɺ���֮����
�ſ�վ�����ױ���ʿ���䱸ɭ�ϡ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"estreet",
  "eastup" : __DIR__"wfdating",

]));
        set("objects", ([
        __DIR__"npc/weishi1" : 2,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-780);
        set("coor/y",-700);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}