#include <ansi.h>
inherit ROOM;
#include <room.h>

void create()
{
        set("short",MAG "洗澡堂" NOR);
        set("long", @LONG
这里是移花宫所有的人洗澡的地方.可能现在
是白天.所以这里一个人也没有.只有澡池里的
水冒出的滚滚热气.你可以在这里洗澡(xizao).
LONG
        );
        set("exits", ([
                  "north" : __DIR__"shuifang",
                  "east" : __DIR__"dating",
        ]));
        set("outdoors", "fengyun");
	set("no_magic", 1);
        set("coor/x",-190);
	set("coor/y",225);
	set("coor/z",30);
	setup();

}

void init()
{
	add_action("do_xizao", "xizao");

}

int do_xizao()
{
	object me;
	int wait;
	me = this_player();
        wait = random((int)me->query("con")) ;
        if ( wait <= 0) wait = 3;
        if ( wait >= 10) wait = 7;
	message_vision("$N缓步走入水中．\n",me);
	tell_object(me,"你感到全身无比的舒泰．．\n");
	remove_call_out("curehimup");
	call_out("curehimup", wait, me);
        return 1;
}

void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
	message_vision("$N的精气神全恢复了！！\n", me);
	me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
	me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
	return;
}

