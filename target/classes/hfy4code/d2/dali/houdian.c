// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�����º��");
        set("long", @LONG
��������������ɮ����֮��������ֻ�����������š�������ɮ����
�о�����һ��С�������Ա����š�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"dadian",
  "west" : __DIR__"huayuan",
  "south" : __DIR__"banruo",
]));
        set("objects", ([
                __DIR__"npc/benguan" : 1,  //�����¸�ɮ ����(Ben guan)
                __DIR__"npc/benxiang" : 1,  //�����¸�ɮ ����(Ben xiang)
                __DIR__"npc/monk2" : 1,
       ]) );
//        set("outdoors", "dali");
        set("coor/x",-970);
        set("coor/y",-800);
        set("coor/z",150);
        setup();
}