 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
����������⣬�����Դ�������������Ϊ�������й������Կ�����
ӵɮ����������������������������������ʦ�䷢���֣�Э�����죬��
������������Ŀ����ɫ��������һӦ��ȫ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bingwest",
]));
        set("objects", ([
                "/obj/weapon/sword" : 1,
                "/obj/weapon/blade" : 1,
                "/obj/weapon/staff" : 2,
                "/obj/weapon/hammer": 1,
                "/obj/weapon/whip"  : 1,
                "/obj/weapon/axe"   : 2,
       ]) );
        set("coor/x",-230);
        set("coor/y",340);
        set("coor/z",70);
        setup();
        create_door("east", "ľ��", "west", DOOR_CLOSED);
}    
