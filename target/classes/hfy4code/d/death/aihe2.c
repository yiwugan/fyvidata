 // TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�κ���");
        set("long", @LONG
�����ű߱��ǽ������䣬�ź���վһ����ͨ�����������������գ�
�Ҷ�ȴ��û�ں���֮�У����µ�������ʽ�ն񣬱�����Ϣ��������
�����ں�ˮ֮����Լ�ɼ���Ӱ��������������������ˮ�߲�����
��������ǰ���ǹ��Ź��ˡ�
LONG
        );
        set("exits", ([
                "west" : __DIR__"gate",
                "east" : __DIR__"ghostinn",
        ]) );
        set("objects", ([
                __DIR__"npc/niutou":1,
                __DIR__"npc/mamian":1,
                __DIR__"npc/ghost" : 5
        ]) );
        set("coor/x",-1010);
        set("coor/y",0);
        set("coor/z",-100);
        setup();
        replace_program(ROOM);
}
 
