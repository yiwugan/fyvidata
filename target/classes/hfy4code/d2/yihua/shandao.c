inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
        ����һ���������������ʻ���ɽ���������졣����
Ӱ�������������������صĸо����ڻ���֮����ϡ�ɼ��۷��
����ȥ,��������ȥֻ��������һ���ߴ�Ĺ�����ϡ�ɼ���
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "northup" : __DIR__"shandao1",
        ]));

        setup();
        replace_program(ROOM);
}
