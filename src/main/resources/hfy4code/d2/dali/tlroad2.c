inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ����ɽС·�����ɴ�����������µ�ɽ·��·�����ָ��ǡ���
����������ɽ�š�
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"tlroad1",
  "westup" : __DIR__"tldoor",
]));
//        set("objects", ([
//        __DIR__"npc/trader" : 3,
//                        ]) );
        set("outdoors", "dali");
        set("coor/x",-940);
        set("coor/y",-800);
        set("coor/z",100);
        setup();
        replace_program(ROOM);

}