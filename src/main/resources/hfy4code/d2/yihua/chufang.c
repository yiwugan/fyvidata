inherit ROOM;
#include <ansi.h>
#include <room.h>


void create()
{
        set("short", HIR"����"NOR);
        set("long", @LONG
��Ȼ�ƻ����ڽ����ϴ�˵����ô����.Ҳ��Ҫ�Է���
��������ԵĲ���"��",����"��",(chihua).
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
"��͵��?�뵽�ᱻ�Լ�ʦ������.���ɵ�������..\n");	
	tell_object(me,"���������ĳ���,˿�������������������񣮣�\n");
	me->set("food",200);
	me->set("water",200);
return 1;
}

