inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "��������");
        set("long", @LONG
����һ��ǧ����ɣ���һ�Ѿ�ɡ���ڰ���С����ܳ���һЩ���٣�
ɽ�����ѿ���һ����죬���������������⣩��ȥ��ֻ�����ɽ
����һ�����ٲ����������գ��������£�����һ���峺�쳣�Ĵ��֮
�С�
LONG
        );
        set("coor/x",-700);
        set("coor/y",-900);
        set("coor/z",140);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        me = this_player();
        if( arg == "down") 
        {
                message_vision("$N��������ɽ������ȥ��\n", me);
                me->move(__DIR__"gudi.c");
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}