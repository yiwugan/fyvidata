#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIC "����" NOR);
        set("long", @LONG
��������������������֮���һ�����ȣ��������������ĵ�����
��ʯ�̳ɵ�С�ȸ����徻�����¡���������һ��С�أ��������㾧Ө
��͸��������һ����ɽ��һ����ϸ��ע����У���һ��ɽˮ��԰ͼ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"zhengdian",
  "west" : __DIR__"qinzhengdian",

]));
//        set("objects", ([
//                __DIR__"npc/master_20" : 1,
//       ]) );
        set("outdoors","dali");
        set("coor/x",-810);
        set("coor/y",-630);
        set("coor/z",90);
        setup();
}