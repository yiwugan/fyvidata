inherit ROOM;
void create()
{
        set("short", "Ʈ���ׯ");
        set("long", @LONG
�����Ǵ������������Ĳ�ׯ������Զ�������Ĳ�Ҷ�����ﶼ���򵽡�����
����������ƷƷ�裬��������������������Ҳ����Ʒ�����������ɫС��
���������ߡ���Ũ���Ĳ������ɫ�Ĳ��������߲�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wroad1",
]));
        set("outdoors", "dali");
        set("objects", ([
         "d/dali/npc/waiter1.c" : 1,
                        ]) );

        set("coor/x",-850);
        set("coor/y",-740);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}
