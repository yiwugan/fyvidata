#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "�鷿" NOR );
        set("long", @LONG
    �鷿��������Ŀ��ȫ��ʫ��伮���������ϰ������ͭ��������
�������ǹ�����Ϲ���һ��ˮī��������ȴ��һλ��װ��Ů������
���洫��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"wfxiaoting",

]));
        set("objects", ([
        __DIR__"npc/duanzhch" : 1,
                        ]) );
         set("outdoors", "dali");
        set("coor/x",-720);
        set("coor/y",-730);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}