inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
�����Ѿ�������۵ĵؽ��ˣ�ֻ����ʯ�̳ɵ�С·��������
����涣�ɽ���ϵ�Ұ�����涷�ޡ�
LONG
        );
        set("exits", ([ 
  "northdown" :  __DIR__"shanroad",
  "south" : __DIR__"yxguan",
]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-950);
        set("coor/z",110);
        setup();
        replace_program(ROOM);

}