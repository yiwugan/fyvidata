#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIG "镇南王府大门" NOR );
        set("long", @LONG
来到府前，只见朱红的大门之前左右旗杆高耸，两头威武狰狞
的玉石狮子盘坐门旁，一排白玉阶石直通到前厅，势派豪雄之极。
门口站满了亲兵卫士，戒备森严。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"estreet",
  "eastup" : __DIR__"wfdating",

]));
        set("objects", ([
        __DIR__"npc/weishi1" : 2,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-780);
        set("coor/y",-700);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}