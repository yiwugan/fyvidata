#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIB "�㳡" NOR);
        set("long", @LONG
    ���������µ�ǰ��һ���㳡����������һЩ�軨���м���һ��
��յأ������۾���������͹��е�����һ��ϼ����㳡����ļ�
��ͭ�˾���ƽʱ�������á�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"lizhengdoor",
  "west" : __DIR__"hglang1",
  "northup" : __DIR__"zhengdedian"
]));
        set("objects", ([
                __DIR__"npc/leader" : 1,
                __DIR__"npc/guard" : 4,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-650);
        set("coor/z",80);
        setup();
}