inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
һ���ǳ������Ĵ�·�����ɴ������������Ĺٵ�����·��
��������ï�ܣ���Ƭ���ָ���ɽ�룬�˼���ƽ�ƽ̹����·������
����Ǻͳ�����
LONG
        );
        set("exits", ([ 
  "northeast" : "/d/chenxiang/cxs1",
  "southwest" : __DIR__"qxroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-500);
        set("coor/y",-600);
        set("coor/z",0);
        setup();
        replace_program(ROOM);

}