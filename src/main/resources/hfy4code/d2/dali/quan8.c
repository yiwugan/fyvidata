inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
һƬï�ܵ��ȴ���(tree)�֡���Ҷ��ס��̫������ǰ�������ʵģ���
���巽��Զ��������ˮ����
LONG
        );
        set("exits", ([
                "north" : __DIR__"quan6",
                "south" : __DIR__"quan2",
                "east" : __DIR__"quan7",
                "west" : __DIR__"quan4",
        ]));


        set("item_desc", ([
                "tree": "�������(tree)���ܣ������ƺ������ƿ�(around)���ǡ�\n",
                "��": "�������(tree)���ܣ������ƺ������ƿ�(around)���ǡ�\n"

        ]) );
        set("outdoors", "dali");
        set("coor/x",-620);
        set("coor/y",-780);
        set("coor/z",80);
        setup();
//      replace_program(ROOM);

}
void init()
{
        add_action("do_push", "around");
}
int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ�ƿ�ʲô��\n");
                return 1;
        }
        if( arg == "tree" || arg == "��")
        {
        me = this_player();
        message_vision("$N�ƿ����������������һ�����ϵ�С·��\n", me);
        if(!me->query("m_success/����Ȫ"))
        {
                me->set("m_success/����Ȫ",1);
                me->add("score",100);

        }
//      if( !query("exits/south") ) {
        set("exits/south", __DIR__"hdquan");
        call_out("close_path", 5);
//      }
        return 1;
        }
        else
        {
                write("�㲻�����ƹ�"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"���ϵ�С·��ʧ�ˡ�\n",
                this_object() );
        set("exits/south", __DIR__"quan2");
//              delete("exits/south");
}
