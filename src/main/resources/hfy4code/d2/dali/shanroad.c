inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������ͨ�������ɽ��һ��Ƨ����С·��ƽʱ�����˼���ֻ��
����ȥ����۽����Ů��͡�
LONG
        );
        set("exits", ([ 
  "north" :  __DIR__"sdoor",
  "southup" : __DIR__"shanroad1",
//  "eastsouth" : __DIR__"dali/???",
]));
        set("objects", ([
        __DIR__"npc/girl1" : 1,
        __DIR__"npc/girl2" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-900);
        set("coor/z",90);
        setup();
        replace_program(ROOM);

}