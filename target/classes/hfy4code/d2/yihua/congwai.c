inherit ROOM;

void create()
{
        set("short", "��԰��");
        set("long", @LONG
�ô��һ����԰�������˸��ֲ軨��������������ɫ�Ļ�����ֻ��
���ڻ��з��衣��԰�м���һ���ǳ���ļ�ɽ������һ����Ȫ�Ӽ�ɽ��
�����������������˵�����......
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"huacong1",
]));
        set("objects", ([
                __DIR__"npc/master1" : 1,
       ]) );
        set("item_desc", ([
                "jiashan": "һ���ǳ���ļ�ɽ��\n",
                "��ɽ": "һ���ǳ���ļ�ɽ��\n"

        ]) );

        set("outdoors", "yihua");
        set("no_magic",1);
        set("coor/x",-190);
	set("coor/y",250);
	set("coor/z",30);
        setup();
}
void init()
{
        add_action("do_push", "push");
}

void close_path()
{
        if( !query("exits/westdown") ) return;
        message("vision",
"��ɽ���˻Σ�������·����ʧ�ˡ�\n",
                this_object() );
                delete("exits/westdown");
}

int do_push(string arg)
{
 object obj;
 object me;
 if(!arg || arg=="")
  {
   write("��Ҫ��ʲô��\n");
   return 1;
  }
 me = this_player();
 if( arg == "jiashan" || arg == "��ɽ")
  {
   if( (int) me->query("force_factor") >= 120 )
    {
     message_vision("$N�����������Ƽ�ɽ����ɽ��Ȼ�ζ���һ�£�¶����һ��������·��\n", me);
     if(!me->query("m_success/����������"))
      {
       me->set("m_success/����������",1);
       me->add("score",1500);
      }
     if( !query("exits/west") )
      {
       set("exits/westdown", __DIR__"dishi");
       call_out("close_path", 5);
      }
     return 1;       
    }
    else
     {
      write("���������Ƽ�ɽ����û���ƶ���\n");
      return 1;
     }
  }
  else
   {
    write("�㲻������"+arg+"\n");
    return 1;
   }
}
