inherit ROOM;

void create()
{
        set("short", "�Ϲ�Ǯׯ");
        set("long", @LONG
��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����˼�Ǯׯ���Һ��֣������Ϲ���ҵ֮
һ���Ϲ�Ǯׯ����Ʊ�������ã����ϱ����ɶ��֡����Ǹ��ɵй��Ľ�Ǯ�Ҳ����
�����Ǯׯ������һ��ľ��̨�����˶�ߣ������ƣ�����һ�顣
[31m
                                �Ϲ�Ǯׯ
[37m
LONG
        );
        
        set("exits", ([
                "east"          : __DIR__"sroad1",
        ]) );
        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
loan        ��Ǯׯ��Ǯ��
TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/shisi" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-810);
        set("coor/y",-800);
        set("coor/z",80);
        setup();
}