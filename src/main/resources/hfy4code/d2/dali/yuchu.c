#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "������" NOR);
        set("long", @LONG
������չ��ʡ�������������������ͨ��������������æ��Ϊ
����׼����͡��������ݵ���ζ���ȣ������Ų��ɵ�ֱ����ˮ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jiamingdian",

]));
//        set("objects", ([
//                __DIR__"npc/master_20" : 1,
//       ]) );
        set("outdoors","dali");
        set("coor/x",-830);
        set("coor/y",-650);
        set("coor/z",80);
        setup();
}