 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽ��");
        set("long", @LONG
����ǰ�ߣ���·��Ϊ��������������ϡ��������ż�����ܼ�������
�������������˼�����ɱ֮�����������������¡���ѹҲ��֮��
�͡�һʱ�䣬�ƺ��ӿ���ͻȻ���뵽�϶���
ԶԶ��ȥ������������������֮�С�
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"yuzhu",
        "east" : __DIR__"kunlun2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
