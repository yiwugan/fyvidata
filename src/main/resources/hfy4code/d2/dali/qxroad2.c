inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
һ���ǳ������Ĵ�·�����ɴ������������Ĺٵ�������Խ��
Խ�ߣ�·������Լ�ɼ����಻����ɽ����
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"qxroad1",
  "southwest" : __DIR__"qxroad",
]));
        set("objects", ([
        __DIR__"npc/girl" : 2,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-550);
        set("coor/y",-650);
        set("coor/z",50);
        setup();
        replace_program(ROOM);

}