 // TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���Ź�");
        set("long", @LONG
��һ���ѣ��������ڹ��Źأ��ߴ�ĳ�ǽ��μˮ���ƣ�����ɭɭ����
����Ŀ������ţͷ�������ֳ��������س��ţ��������ֳ�����������ק��
������Ӱ���˽�ȥ��������������������¥�ϸ���һ�����ң�
 
                        ���Ź�
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "south" : __DIR__"naihe",
                "east" : __DIR__"aihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/niutou":1,
                __DIR__"npc/mamian":1,
                __DIR__"npc/panguan" : 1,
        ]) );
        set("no_magic",1);
        set("coor/x",-1020);
        set("coor/y",0);
        set("coor/z",-100);
        setup();
        replace_program(ROOM);
} 
