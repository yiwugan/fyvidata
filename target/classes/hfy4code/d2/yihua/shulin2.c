//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
��ǰ��һ���޼ʵ����֣�û��·�꣬Ҳû��һ�����ˣ���
�Եúܸߣ�Զɽ��ѩ����ӥ���裬������ãã�ֺ�֮�У����ƺ�
��·�ˡ�
LONG );
 	set("exits",([
	    "east" : __DIR__"shulin1",
	    "west" : __DIR__"shulin2",	
	    "north" : __DIR__"shulin3",
	    "south" : __DIR__"shulin2",  				
	]));
        set("coor/x",-175);
	set("coor/y",190);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}