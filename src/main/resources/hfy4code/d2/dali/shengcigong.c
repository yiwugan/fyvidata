#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "ʥ�ȹ�" NOR);
        set("long", @LONG
ʥ�ȹ��Ǵ���ʹ���ǰ������������������̷��裬����������
�ɶ��칤������Ϲ���һ�������������ġ���Ȫ��ˮ���������
��ȥ�����н����������̻Ի͡�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"paifang",
  "north" : __DIR__"lizhengdoor",
]));
       set("objects", ([
        __DIR__"npc/xtaijian" : 2,
                       ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-670);
        set("coor/z",80);
        setup();
}