#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG "��������" NOR);
        set("long", @LONG
    �����ڴ���ǵ�������ϣ��������ʯƽ�̡�����������̳�
�ܣ���������������һ��������԰�ľ�������·�����濴����ᷢ��
��һ�Ҵ�����Ժ�������м�Ʒ���ׯ�����������ֵ��ϣ�һ��Ũ���Ĳ����
�����ذ�Χ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"dalicenter",
  "west" : __DIR__"wroad2",
  "north" :__DIR__"chazhuang",
  "south" :__DIR__"qiyuan",
]));
        set("outdoors", "dali");
        set("coor/x",-850);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}