#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HBMAG"��������" NOR);
        set("long", @LONG
    �����Ǵ���������ţ����Ǿ��Ǵ��СС��ɽȺ����һ��
���˲��ࡣ
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"tlroad1",
  "east" : __DIR__"wroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-900);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);


}