// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�����´��");
        set("long", @LONG
��������������ɮ�����֮�������ڳ��輫Ϊ�򵥣�����ǰ����һ
�����������ϵ���¯�в��ż����㡣���ϰ����������š���һ��С����
���ڴ�ɨ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"tldoor",
  "west" : __DIR__"houdian",
]));
        set("objects", ([
                __DIR__"npc/bencan" : 1, //�����¸�ɮ ����(Ben can)
                __DIR__"npc/monk1" : 1,
                __DIR__"npc/pker" : 1,
       ]) );
//        set("outdoors", "dali");
        set("coor/x",-960);
        set("coor/y",-800);
        set("coor/z",150);
        setup();
}
