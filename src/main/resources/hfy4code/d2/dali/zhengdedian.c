#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "���µ�" NOR);
        set("long", @LONG
�����ǳеµ�ǰ��һ���������Ǹ����ϳ�ʱ��Ϣ�õġ�����
�Ѿ�ɢ���ˣ�ֻ�м�����ʿ�ڵ���ִ�ڡ�����ǰ�������͵��˻ʹ�
�����ĳеµ
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"guangchang",
  "north" : __DIR__"zhengdian",

]));
        set("objects", ([
                __DIR__"npc/jinyi" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-640);
        set("coor/z",90);
        setup();
}