//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "ǰ��");
	set("long", @LONG
����һ��ܴ�Ŀ���.�ǳ��Ĵ�.����ǽ�ڹ�����
��Ů�Ļ�.��˵��ÿһ���ƻ�������λ������.��
���ƻ����ڽ���������һ��ת�ƾõ�����.
LONG );
 	set("exits",([
	    "north" : __DIR__"dating",
	    "east" : __DIR__"chufang",  				    "south" : __DIR__"damen",
	]));
        set("coor/x",-180);
	set("coor/y",220);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
