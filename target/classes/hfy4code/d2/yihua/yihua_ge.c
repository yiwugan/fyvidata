inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
����ǡ��ƻ������Ļ����󡣷����ﵽ�������ʻ���������
���ϰ����ʻ�������ģ�Ҳ��һЩ�в��������滨��ݣ����˳��档
LONG
        );
        set("exits", ([
                "north" : __DIR__"damen",
                "south" : __DIR__"changlang",
                "west" : __DIR__"liangong",
                "east" : __DIR__"sleeproom",
        ]));

        set("objects",([
        "/d/yihua/npc/yuenu" : 1,
        ]));
        set("coor/x",-160);
        set("coor/y",135);
        set("coor/z",0);
        set("valid_startroom", 1);
        setup();   }
