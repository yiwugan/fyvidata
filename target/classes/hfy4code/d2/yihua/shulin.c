//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
���ڴ�����С������ǰ��һ���޼ʵ����֣�û��·�꣬Ҳû
��һ�����ˣ����Եúܸߣ�Զɽ��ѩ����ӥ���裬��һ�ɲ�
ͬ�������������⡣��Զ������ֻ�׹�ɢ�����,�����˵�ʬ��?
������ãã����֮�У����ƺ���·�ˡ�
LONG );
 	set("exits",([
		      "east" : __DIR__"xiaojing3",
		      "west" : __DIR__"shulin1",	
		      "north" : __DIR__"shulin",
                      "south" : __DIR__"shulin",  				
	]));
        set("coor/x",-165);
	set("coor/y",190);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
