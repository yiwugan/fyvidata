//yixin@bft.c

inherit ROOM;

void create()
{
        set("short", "��������");
	set("long", @LONG
���ڵ���һ����ս.�����ȫ�������.��Ϊ����
��������������������С�
LONG );
        set("exits", ([ 
  "east" : __DIR__"dishi",
])); 
        set("objects",([
          "d/yihua/npc/yannantian":1
        ]) );
        set("coor/x",-190);
	set("coor/y",250);
	set("coor/z",20);
        set("no_magic",1);
        set("no_dazuo",1);
	setup();
        replace_program(ROOM);
}
