//yixin@bft.c
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�����ƻ�������ƽ��˯���ĵط�.����ڷ���ʮ��
����ʯ���Ĵ�.��������Ҫ�ߵ�����Ķ�.�ɼ���
���Ա��ŵ��ӵĹ���֮΢.
LONG );
 	set("exits",([
	    "south" : __DIR__"chang",  				
	]));
        set("coor/x",-190);
	set("coor/y",227);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
}
