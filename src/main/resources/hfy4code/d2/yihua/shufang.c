//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "�鷿");
	set("long", @LONG
���ǻ���ȱƽ�������ж���ĵط�.��Ȼ��һ��֮��.
ȴ��������û�ձض�����дһ��.
LONG );
 	set("exits",([
	    "north" : __DIR__"woshi",
	    "west" : __DIR__"dating",  				
	]));
        set("coor/x",-170);
	set("coor/y",225);
	set("coor/z",30);
	set("no_magic", 1);
	setup();
	replace_program(ROOM);
}
