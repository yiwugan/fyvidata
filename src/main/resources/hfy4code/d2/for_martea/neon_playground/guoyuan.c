#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"����ݵ�"NOR);
    set("long", @LONG
һƬ�ļ����̵Ĳݵء�
�����͵�ϸ�ݣ�����ú��������˵�ͷ�����ݵ���������Զ��һƬ�����֡�
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"shanpo",
        "south" : __DIR__"kezhan",
        "west" : __DIR__"smallyard",
        ]));
        set("outdoors","neon_playground");
        set("coor/x",0);
        set("coor/y",30040);
        set("coor/z",0);
        setup();
}     
