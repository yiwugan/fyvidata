#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "������" NOR);
        set("long", @LONG
�������Ǳ����۵��޹����ڵأ����������ʹ���������գ���
����װ��Ů������ʰ���䡣������������Ǽ���С��Ǿ���
�ʵ���Ϣ�ĵط��ˡ�
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"xiaoyuan",
  "west" : __DIR__"qingong",
  "east" : __DIR__"hglang2",
]));
        set("objects", ([
                __DIR__"npc/gongnv" : 1,
                __DIR__"npc/xtaijian" : 1,
       ]) );
        set("outdoors","dali");
        set("coor/x",-820);
        set("coor/y",-630);
        set("coor/z",90);
        setup();
}