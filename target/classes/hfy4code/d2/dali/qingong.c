#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "�޹�" NOR);
        set("long", @LONG
�����ǻʵ۵��޹�������һֻ��¯��Ѭ��һ��̴�㣬��������
�������ƣ����˻����˯��������ɴ���ᴹ��������ʰ���˳���Ⱦ��
����̫��͹�Ů����ͣ����ʰ���䡣
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"qinzhengdian",
]));
        set("objects", ([
                __DIR__"npc/gongnv" : 1,
                __DIR__"npc/xtaijian" : 1,
       ]) );
        set("outdoors","dali");
        set("coor/x",-830);
        set("coor/y",-630);
        set("coor/z",90);
        setup();

}