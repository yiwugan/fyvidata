// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������µ��������ķ��䣬���ڼ򵥵س�����һЩ�����ر�
����Ʒ������������ɮ���������������붨��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"lang1",
]));
        set("objects", ([
                __DIR__"npc/monk3" : 2,
       ]) );
        set("outdoors", "dali");
        set("coor/x",-960);
        set("coor/y",-820);
        set("coor/z",150);
        setup();
}