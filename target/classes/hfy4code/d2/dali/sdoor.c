#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HBMAG "��������" NOR);
        set("long", @LONG
�˼��Ǵ����������ǵ����ţ������ʵ��������ǣ���گ�ڳ�
��������������������Ķ��ϵġ�������������Դ˳�Ϊ������ǽ��
ʯ������ݳɣ��߶����壬�����ɡ��������������������ľ�ʿ��
�����۾��۲����������������ˣ�ż�����ʼ����μ����ɷ��ӡ�

LONG
        );
        set("exits", ([ 
  "north" : __DIR__"sroad2",
  "south" : __DIR__"shanroad",
]));

//        set("objects", ([
//        __DIR__"npc/trader" : 3,
//                        
//  ]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-850);
        set("coor/z",80);
        setup();
        replace_program(ROOM);


}