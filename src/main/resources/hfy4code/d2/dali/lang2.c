#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������ڳ�����һ�����ȣ�ǰ���Ǽ�����ݣ�ȫ����ľ��ɣ���
��ľ����ľ�Ͼ���ȥƤ����Ȼ���ӣ�ȴ��ǰ��һ·�����Ľ�̻Ի͵ĵ�
�ý�Ȼ��ͬ��������һ��С�ţ�û�з��ɵ������κ��˲������롣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "north" : __DIR__"jingge",
    "east" : __DIR__"lang1",
]));        
        set("outdoors", "dali");
        set("coor/x",-980);
        set("coor/y",-820);
        set("coor/z",150);
        setup();
        create_door("north", "ʯ��", "south", DOOR_CLOSED);
}