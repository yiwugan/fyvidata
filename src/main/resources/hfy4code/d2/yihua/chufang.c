inherit ROOM;
#include <ansi.h>
#include <room.h>


void create()
{
        set("short", HIR"花房"NOR);
        set("long", @LONG
虽然移花宫在江湖上传说在怎么神奇.也是要吃饭的
不过这里吃的不是"饭",而是"花",(chihua).
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"qiandian",
]));
        set("coor/x",-170);
	set("coor/y",220);
	set("coor/z",30);
	setup();
}

void init()
{
	add_action("do_chihua", "chihua");

}

int do_chihua()
{		object me;
		me = this_player();
if(me->query("class") != "yihua") return notify_fail(
"想偷吃?想到会被自己师父责骂.不由得心虚了..\n");	
	tell_object(me,"你如饿虎般的吃着,丝毫不顾旁人异样的眼神．．\n");
	me->set("food",200);
	me->set("water",200);
return 1;
}

