// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ɮ����֮�������ڳ��輫Ϊ�򵥣�����ǰ����һ
�����������ϵĹ�ƷӦ�о��С����ϰ����������š������Ǿ���֮����
���������ر���ྲ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"houdian",
  "south" : __DIR__"lang1",
]));
        set("objects", ([
                __DIR__"npc/benchen" : 1, //�����¸�ɮ ����(Ben chen)
                __DIR__"npc/monk5" : 2,
       ]) );
//        set("outdoors", "dali");
        set("coor/x",-970);
        set("coor/y",-810);
        set("coor/z",150);
        setup();
}