//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
��.�������ǻ�.����ȫ�ǻ�.�㲻����ʼ�������
���ֵط�.����·��.�㿴���е�Ŀ��������.
LONG );
 	set("exits",([
	    "southwest" : __DIR__"huayuan",
            "southeast" : __DIR__"huacong",
            "northwest" : __DIR__"huacong",
            "northeast" : __DIR__"huacong",
            "south" : __DIR__"huacong",
            "north" : __DIR__"huacong",
            "west" : __DIR__"huacong",
	    "east" : __DIR__"huacong",  				
	]));
        set("no_magic",1);
        set("coor/x",-178);
	set("coor/y",242);
	set("coor/z",30);
        set("objects", ([
                __DIR__"npc/huhua" : 1,
                __DIR__"npc/huhua1" : 1,
       ]) );
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
