inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ����ɽС·�����ɴ�����������µ�ɽ·��·�����ָ��ǡ���
���Ǵ�������š�
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"wdoor",
  "southwest" : __DIR__"tlroad2",
]));
//        set("objects", ([
//        __DIR__"npc/trader" : 3,
//                        ]) );
        set("outdoors", "dali");
        set("coor/x",-920);
        set("coor/y",-780);
        set("coor/z",100);
        setup();
        replace_program(ROOM);

}