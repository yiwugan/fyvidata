inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·����ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ���
���Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£���������������
�ף���ʱ���˺�����������Ҫ��Хһ������������һƬ�յء�������
�����ƻ�С����
LONG
        );
        set("outdoors", "yihua");
        set("exits", ([
                "southdown" : "/d/songshan/junji",
                "northup"   : __DIR__"shanlu2",
        ]));
        set("coor/x",-180);
	set("coor/y",160);
	set("coor/z",20);
        setup();
        replace_program(ROOM);
}
