inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�ô��һ����԰�������˸��ֲ軨��������������ɫ�Ļ�����ֻ��
���ڻ��з��衣��԰�м���һ���ǳ���ļ�ɽ������һ����Ȫ�Ӽ�ɽ��
�����������������˵�������Զ����Լ����������......
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"houdian",
]));
        set("objects", ([
                __DIR__"npc/monk4" :1,
        ]) );

        set("item_desc", ([
                "jiashan": "һ���ǳ���ļ�ɽ��\n",
                "��ɽ": "һ���ǳ���ļ�ɽ��\n"

        ]) );

        set("outdoors", "dali");
        set("coor/x",-730);
        set("coor/y",-810);
        set("coor/z",150);
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
     if(!me->query("m_success/������"))
      {
       me->set("m_success/������",1);
       me->add("score",150);
      }
     if( !query("exits/west") )
      {
       set("exits/westdown", __DIR__"jingshe");
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