inherit ROOM;
void create()
{
        set("short", "�ͱ�");
        set("long", @LONG
�����ͱ���һ������Ĵ�ʯ������ЪЪ�š�
LONG
        );
        set("outdoors", "dali");
        set("coor/x",-710);
        set("coor/y",-900);
        set("coor/z",100);
        setup();
}
init()
{
add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object  me;
        int     mlvl;

        if(!arg || arg != "up") {
                write("��Ҫ����������\n");
                return 1;
        }
        me = this_player();
        {       message_vision( "\n$N�����ͱ�������������ȥ��\n" , me);
                me->start_busy(4);
                call_out("fliping",4,me);
                me->stop_busy();
        }
        return 1;
}

int fliping(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"biding");
        message_vision("$N˳���ͱ�����������\n", me);
        }
        return 1;
}