//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "�ƻ�������");
	set("long", @LONG
������������.��������ɱ��.����ǳ��İ���
ֻ��һ������������.����˲�ͣ��ϴ���Լ���
��.��ͣ��ϴ��.........
LONG );
 	set("exits",([
	    "north" : __DIR__"houyuan",
	    "east" : __DIR__"shufang",  				    "west" : __DIR__"chang",
            "south" : __DIR__"qiandian",
	]));
        set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
        set("coor/x",-180);
	set("coor/y",225);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
