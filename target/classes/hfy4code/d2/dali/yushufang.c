#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "���鷿" NOR);
        set("long", @LONG
�����ǻʹ������鷿������������ŷ��̣��鷿��Ҳ����
��Ҿ��䡣���ڴ����������ϰ�䣬����Ҳ�ղ��˴�����ϵĲ�
���书��Ҫ��
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"guangchang1",
]));
        set("objects", ([
                __DIR__"npc/weishi" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-210);
        set("coor/y",330);
        set("coor/z",70);
        setup();
}