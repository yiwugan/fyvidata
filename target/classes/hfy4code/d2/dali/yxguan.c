//lmd@wenxin
inherit ROOM;

void create()
{
        object con,item;

        set("short", "�����");
        set("long", @LONG
�������Ƶ�����ۣ����������ľ��д��£�����ȴ��С��
���磬�����������������ϰ����˹�Ʒ���������������
��Ĥ�ݡ�
                         �ྲ

       �                                    ��

       ��                                    ��

       ��                                    ��

       ��                                    �� 

LONG
        );
        set("exits", ([ 
  "north" :  __DIR__"shanroad1",
]));
        set("objects", ([
        __DIR__"npc/girl" : 1,
        __DIR__"obj/keyhold" : 1,
        __DIR__"obj/key" : 1,
        __DIR__"obj/xianglu" : 1,
        __DIR__"obj/desk" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-980);
        set("coor/z",120);
        setup();
        con = present("��¯",this_object());
        item= present("key", this_object());
        item->move(con);
        con = present("����",this_object());
        item= present("xianglu", this_object());
        item->move(con);
//        replace_program(ROOM);

}

void init()
{
        add_action("do_insert", "insert");
}

void close_path()
{
        if( !query("exits/southdown") ) return;
        message("vision",
"�����µĶ���ʧ�ˡ�\n",
                this_object() );
                delete("exits/southdown");
}

int do_insert(string arg)
{
 object obj;
 object me,con;
 if(!arg || arg=="")
  {
   write("��Ҫ��ʲô��\n");
   return 1;
  }
 me = this_player();
 if( arg == "key hole" || arg == "hole" || arg == "Կ�׿�")
  {
   if(!objectp(con=present("key", me)))
    return notify_fail("������û��Կ�ס�\n");
   message_vision("$N�����Ű�Կ�ײ����ǽ�ǵ�һ�������ص�Կ�׿��ת����һ��,\n����֨֨�������������³�����һ������\n", me);
   if(!me->query("m_success/����ɽ"))
    {
     me->set("m_success/����ɽ",1);
     me->add("score",100);
    }
   if( !query("exits/southdown") )
    {
     set("exits/southdown", __DIR__"hole1");
     call_out("close_path", 5);
    }
   return 1;       
  }
  else
   {
    write("�㲻���Ҳ�!!\n");
    return 1;
   }
}