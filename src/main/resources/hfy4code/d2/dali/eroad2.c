#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG "������" NOR);
        set("long", @LONG
��ǰ��һ������ɫ��ʯ�̳ɵĴ������·��ֱ������ͨ�����Ǳ��ţ�����
�͵��˴���ǵ����ġ�·����������������Ļ��ݡ�͸��һ���꿪�����޵Ĳ軨
�����Կ�ȥ����ᷢ��·��������һ���ӻ��̣�·�ı�����һ�ҳ����̡�

LONG
        );
        set("exits", ([ 
  "east" : __DIR__"edoor",
  "west" : __DIR__"eroad1",
  "south" :__DIR__"zahuopu",
  "north" :__DIR__"chengyipu",
]));
        set("objects", ([
                __DIR__"npc/girl1" : 1,
                __DIR__"npc/man1" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-720);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}