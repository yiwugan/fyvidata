inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
һ���ǳ������Ĵ�·�����ɴ������������Ĺٵ�������һ��Сɽ��
ɽ�����·𿴵õ����ϵĴ���ǡ�
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"qxroad2",
  "southwest" : __DIR__"ting",
]));
        set("outdoors", "dali");
        set("coor/x",-600);
        set("coor/y",-700);
        set("coor/z",100);
        setup();
        replace_program(ROOM);

}
