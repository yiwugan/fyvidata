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
	    "southwest" : __DIR__"huacong",
            "southeast" : __DIR__"huacong",
            "northwest" : __DIR__"huacong",
            "northeast" : __DIR__"huacong",
            "south" : __DIR__"houyuan",
            "north" : __DIR__"huacong",
            "west" : __DIR__"huacong",
	    "east" : __DIR__"huacong",  				
	]));
        set("coor/x",-170);
	set("coor/y",240);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
