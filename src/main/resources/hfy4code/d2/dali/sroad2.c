#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG "�����Ͻ�" NOR);
        set("long", @LONG
        ��ǰ��һ����ֱ�Ĵ�ʯ·��·����ʯƽ�̣���ͨ�������Ļʹ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"sroad1",
  "east" : __DIR__"huadian",
  "west" : __DIR__"chayuan",
  "south" : __DIR__"sdoor",
]));
        set("objects", ([
        __DIR__"npc/dtz" : 3,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-830);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}