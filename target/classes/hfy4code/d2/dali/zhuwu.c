inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ��С���ݣ���ʰ�øɾ����ʣ�һ���ǳ�����������Ů����
�ڴ�ǰ��������������ʱ����һ����̾Ϣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhulin",
]));
   //     set("no_fight",1);
        set("no_magic",1);
        set("outdoor","dali");
        set("coor/x",0);
        set("coor/y",-450);
        set("coor/z",10);
        set("objects", ([
                __DIR__"npc/wangyuyan" : 1,
       ]) );
        setup();
}