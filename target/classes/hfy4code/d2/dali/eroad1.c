#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG "������" NOR);
        set("long", @LONG
��ǰ��һ������ɫ��ʯ�̳ɵĴ������·��ֱ������ͨ�����Ǳ��ţ�����
�͵��˴���ǵ����ġ�·����������������Ļ��ݡ�͸��һ���꿪�����޵Ĳ軨
�����Կ�ȥ����ᷢ��·��������һ�ұ����̣�·�ı�����һ��ӭ���Ƽҡ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"dalicenter",
  "east" : __DIR__"eroad2",
  "south" :__DIR__"bingqipu",
  "north" :__DIR__"jiujia",

]));
        set("objects", ([
                __DIR__"npc/girl" : 1,
                __DIR__"npc/man" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-750);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}