#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIB "�㳡" NOR);
        set("long", @LONG
���������鷿ǰ��һ��Ƭ�㳡���ʵ�ɢ���󾭳�Ҫ���鷿��
�飬�������������䱸���ϣ�һ��Ҳ���Ҵ��⡣
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"zhengdian",
  "eastup" : __DIR__"yushufang",
]));
        set("objects", ([
                __DIR__"npc/jinyi" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-210);
        set("coor/y",330);
        set("coor/z",70);
        setup();
}