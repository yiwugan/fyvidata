#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIM "����԰" NOR);
        set("long", @LONG
�����Ǵ���ʹ�������԰��԰�ڵĲ軨�������ޡ��軨�Ǵ����
���������ʹ��ڵĲ軨��������ϡ�У���������֮����������һָ��
԰�з��ż�����ź����ϡ����ˡ����ܵ��ʹ������϶��ż������ȣ�
�����ʵ���˯֮ǰ�������������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"qulang2",
]));
        set("objects", ([
                __DIR__"npc/gongnv" : 2,
                __DIR__"npc/xtaijian" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-780);
        set("coor/y",-600);
        set("coor/z",80);
        setup();
}