inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������ڳ�����һ�����ȣ�����С��������һ�ԡ�����һֱ��
�����죬ͨ����Ժ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "south" : __DIR__"zhuchi",
    "north" : __DIR__"banruo",
    "west" : __DIR__"lang2",
    "east" : __DIR__"liangong",
]));        
        set("objects", ([
                __DIR__"npc/monk5" : 2,
       ]) );
        set("outdoors", "dali");
        set("coor/x",-970);
        set("coor/y",-820);
        set("coor/z",150);
        setup();
}