#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",CYN "����" NOR);
        set("long", @LONG
������������һ�����������ȣ������ƹ����߹��������
һ��С�����������ϣ�����������壬Զ������������ˮ�������
�����������㣬�ͥԺ����Ȼ����ɽ��Ұ���⾳��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"zhengdian",
  "northeast" : __DIR__"qulang2",

]));
        set("objects", ([
                __DIR__"npc/gongnv" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-610);
        set("coor/z",90);
        setup();
}