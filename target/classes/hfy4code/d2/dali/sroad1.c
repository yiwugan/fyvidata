#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG "�����Ͻ�" NOR);
        set("long", @LONG
        ��ǰ��һ����ֱ�Ĵ�ʯ·��·����ʯƽ�̣�ͨ�������Ļʹ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"dalicenter",
  "south" : __DIR__"sroad2",
  "east" : __DIR__"pawn1",
  "west" : __DIR__"bank1",
]));
         set("objects", ([
         __DIR__"npc/fan1" : 1,
                         ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-800);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}