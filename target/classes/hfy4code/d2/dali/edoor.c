#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HBMAG "������" NOR);
        set("long", @LONG
������ǣ���������ǣ����Ǵ�����Ķ��ǡ����ϳ���������
�����ϡ�����͹��������ϡ������˹��������ϡ����������������
������Ķ��ϵġ�������������Դ˳�Ϊ�����˴����Ƕ����ţ���÷
"ϪΪ���ӣ���ǽ����Ϫ�ϣ���ʯ������ݳɣ��߶����壬�����ɣ�
��������¥��פ�����ڡ���ʯ�ٵ��ӳ���ֱ�������죬����һ������
��·��ͨȥ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"ting",
  "west" : __DIR__"eroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-700);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);


}