inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���᲻�󣬲��õ÷ǳ����¡���ǽ���Ÿ�����ܣ���������˸��ַ𾭣�һ����
��������һ����Ůͼ��һλ������������������ǰ�����ﻹ�ֹ���ʲô��
LONG
        );
        set("exits", ([
                "eastup" : __DIR__"huayuan",
        ]));
        set("no_magic",1);
        set("NONPC",1);
        set("objects", ([
                __DIR__"npc/duanyu": 1,
        ]) );
        set("coor/x",-990);
        set("coor/y",-800);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}