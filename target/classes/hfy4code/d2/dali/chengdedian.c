#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIY "�еµ�" NOR);
        set("long", @LONG
������Ǵ�����Ľ�𽱦�������еĳ���Ҫ��ȫ��������
�������ڳ��軪���������������֮״����ΰ׳����������ԡ�
���г��ϵ����������Ŵ��������ʵ۱����ۡ�
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"zhengdian",
]));
        set("objects", ([
                __DIR__"npc/duanzhm" : 1,
                __DIR__"npc/jinyi" : 2,
                __DIR__"npc/xtaijian" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-620);
        set("coor/z",100);
        setup();

}