#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",CYN "����" NOR);
        set("long", @LONG
����С���ϵ�һ�����������ȣ������ƹ����߹���������ϣ�
����������壬Զ������������ˮ������������������㣬�
ͥԺ����Ȼ����ɽ��Ұ���⾳��
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"qulang1",
  "east" : __DIR__"yuhuayuan",
]));
//        set("objects", ([
//                __DIR__"npc/master_20" : 1,
//       ]) );
        set("outdoors","dali");
        set("coor/x",-790);
        set("coor/y",-600);
        set("coor/z",80);
        setup();
}