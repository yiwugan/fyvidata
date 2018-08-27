#include <ansi.h>
inherit ROOM;
#include <room.h>

void create()
{
        set("short",MAG "ϴ����" NOR);
        set("long", @LONG
�������ƻ������е���ϴ��ĵط�.��������
�ǰ���.��������һ����Ҳû��.ֻ��������
ˮð���Ĺ�������.�����������ϴ��(xizao).
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
	message_vision("$N��������ˮ�У�\n",me);
	tell_object(me,"��е�ȫ���ޱȵ���̩����\n");
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
	message_vision("$N�ľ�����ȫ�ָ��ˣ���\n", me);
	me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
	me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
	return;
}

