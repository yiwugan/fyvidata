inherit ROOM;

void create()
{
        set("short", "ʮ�ﳤͤ");
        set("long", @LONG
    ����һ����·�ڣ���Զ��������ʮ�ﳤͤ�������������׺���
���Ǵ˴���ͤ�����Ǵ���ǣ��ɴ˶���ȥ��ͨ���������ĳ������
��������������������ġ�����Ȫ������˵���ΰٲ���
LONG
        );
        set("exits", ([ 
  "northeast" :  __DIR__"qxroad",
  "west" : __DIR__"edoor",
  "southeast" : __DIR__"quan1",
]));
        set("objects", ([
        __DIR__"npc/girl1" : 1,
        __DIR__"npc/man1" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-650);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}