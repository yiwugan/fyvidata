#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "������" NOR);
        set("long", @LONG
�������Ǵ���ʹ��������ŵ����ڣ����޹����ڵ����������ڡ�
���ܽ����״ӡ������й��ᾯ�����ǽ��ϡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"hglang1",
  "west" : __DIR__"yuchu",
  "north" : __DIR__"xiaoyuan",

]));
        set("objects", ([
                __DIR__"npc/leader" : 1,
                __DIR__"npc/guard" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-820);
        set("coor/y",-650);
        set("coor/z",80);
        setup();
}