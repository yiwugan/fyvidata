#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "������" NOR);
        set("long", @LONG
    �����Ǵ��ǰ�������š�������ȥ���������컧������������
�ݶ�����ͭ�ߣ������������֮״��Ρ��׳������ҫ��Ŀ����������
������������Ѳ�ӡ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"shengcigong",
  "north" : __DIR__"guangchang",
]));
        set("objects", ([
                __DIR__"npc/jinyi" : 2,
       ]) );
        set("coor/x",-800);
        set("coor/y",-660);
        set("coor/z",80);
        set("outdoors","dali");
        setup();

}