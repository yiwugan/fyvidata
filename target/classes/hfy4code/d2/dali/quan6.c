inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
һƬï�ܵ��ȴ����֡���Ҷ��ס��̫������ǰ�������ʵģ���
���巽��Ա��������ˮ����
LONG
        );
        set("exits", ([
                "north" : __DIR__"quan3",
                "south" : __DIR__"quan6",
                "east" : __DIR__"quan7",
                "west" : __DIR__"quan4",
        ]));
       if(!random(4)) set("exits/south" , __DIR__"quan2");
        set("outdoors", "dali");
        set("coor/x",-620);
        set("coor/y",-780);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}