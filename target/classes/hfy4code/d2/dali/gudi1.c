inherit ROOM;
void create()
{
        set("short", "����ɽ��");
        set("long",@LONG 
����һ��ʯ�ң�ʯ���з���һ��ʯ������ǰ�еʣ���������һ��ͭ��������
����Щ���ӡ������������ǹ�����ӡ�ͭ��������ͭ�̣�����Ҳ�ǳ����������
֪���ж�����û�������ˡ��������з���һ������Ů�����񣬵�̵�����������
����Ůһ�㡣��ǰ��һ��һС�������Ź��˹���á�

                         ���������£��˼�����Ҳ��
        
LONG
        );
        set("exits", ([
                "east" : __DIR__"gudi2",
                "south" : __DIR__"gudi3",
           ]));
        set("item_desc", ([
        "����": "��������ǧ�飬�������ߣ����������������޻ڡ��������ˣΣţţ��ɡ���\n\n",
        "xiang": "��������ǧ�飬�������ߣ����������������޻ڡ��������ˣΣţţ��ɡ���\n\n",
        ]) ); 
        set("no_magic",1);
        set("coor/x",-700);
        set("coor/y",-890);
        set("coor/z",90);
        setup();
}

init() 
{
        add_action("do_knee","knee");
}

int do_knee()
{
 object me,con,tu;

 me=this_player();
 message_vision("$N�ߵ�����ǰ���ϵ�Ĥ����ȥ��\n",me);
        if (me->query("xvt_over"))
              return notify_fail("���Ȼ������ʲô�������˳�����\n");
 if(!random(10))
   if(!objectp(con=present("xiannv-tu", me)))
    {
     message_vision("$N��Ȼ������ʲô�������˳������Ͻ����뻳�С�\n",me);
     tu = new(__DIR__"obj/tu");
    tu->set("names",me->query("name"));
     this_player()->set("xvt_over",1);
     tu->move(me);
    }
 return 1;
}
