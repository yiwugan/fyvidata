#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "����" NOR);
        set("long", @LONG
�����ǳеµ�ǰ��һ����������ǳ����ϳ�����֮·�����
���ڼ�ʿ�������䱸ɭ�ϡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"guangchang1",
  "south" : __DIR__"zhengdedian",
  "west" : __DIR__"hglang2",
  "north" : __DIR__"qulang1",
  "northup" : __DIR__"chengdedian",

]));
        set("objects", ([
                __DIR__"npc/weishi" : 2,
                __DIR__"npc/jinyi" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-630);
        set("coor/z",90);
        setup();

}