inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ��Ƨ����ɽ��С·���������˼���·�����ָ����ܵ�
�Ӳݡ�������һƬ���֡�
LONG
        );
        set("exits", ([ 
  "northeast" :  __DIR__"quan7",
  "southwest" :  __DIR__"shanroad2"
]));
        set("outdoors", "dali");
        set("coor/x",-650);
        set("coor/y",-840);
        set("coor/z",80);
        setup();
}