 inherit ROOM;
void create()
{
        set("short", "�����۴���");
        set("long", @LONG
��ľ�հ屻�����������֡�ǽ�����ܹ����˵������˵�����ử������һ�Ŵ��
��̺���������ɷ�Բ������ɴ�����ʵ�������Ů���������衣�е�����
                        �������¶ӯӯ��
                        ��Ⱦ��֬һ���ᡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"boat3",
  "west" : __DIR__"wting",
  "east" : __DIR__"eting",
  "southup"   : __DIR__"stairs",
]));
       set("objects", ([
        __DIR__"npc/dancer" : 3,
                        ]) ); 
        set("coor/x",-150);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    