inherit ROOM;
void create()
{
        set("short", "�ͱ�����");
        set("long", @LONG
��ǰ��һ���ͱڣ���ʱ��ɽ��Ҳ�Ҳ����ˡ�����һ��
С·��������ͱ�ֱ��������������һƬ���֣��������Ǳ�
��ʱ����Ů�ӵ�̾Ϣ����
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"zhulin",
  "east" : __DIR__"shanroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-710);
        set("coor/y",-900);
        set("coor/z",80);
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
        me->move(__DIR__"qiaobi");
        message_vision("$N˳���ͱ�����������\n", me);
        }
        return 1;
}