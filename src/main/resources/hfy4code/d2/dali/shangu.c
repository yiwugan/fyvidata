inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ�ȼ���һ��Ƨ����С·���������˼���·�����ָ����ܵ�
�Ӳݡ�һ���򶫱���·Ҳ��֪ͨ���ġ�
LONG
        );
        set("exits", ([ 
  "northeast" :  __DIR__"shanroad2"
]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-900);
        set("coor/z",90);
        setup();
}