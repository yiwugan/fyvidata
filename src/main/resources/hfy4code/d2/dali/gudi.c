inherit ROOM;

void create()
{
        set("short", "�����ȵ�");
        set("long", @LONG
�ȵ���һ�����ֻ����������һ�ӴԲ軨��������ҡҷ���ˡ�
�������Բ�Σ���벿�����ڻ���֮�У�������������޷����ϣ�
��������ʯ�ڣ������ȡ�������Դ��
LONG
);
/*        set("exits", ([ 
  "east" : __DIR__"houdian",
]));
        set("objects", ([
                __DIR__"npc/monk4" :1,
        ]) ); */

        set("item_desc", ([
                "shibi": "�ڱ�����Լ�н�Ӱ����Ӱбָ�򱱣������׼��һ����ʯ��\n",
                "ʯ��": "�ڱ�����Լ�н�Ӱ����Ӱбָ�򱱣������׼��һ����ʯ��\n",
                "yanshi": "������̦��һ��С��ʯ��\n",
                "��ʯ": "������̦��һ��С��ʯ��\n"
        ]) );

        set("outdoors", "dali");
        set("coor/x",-700);
        set("coor/y",-900);
        set("coor/z",100);
        setup();
}

void init()
{
 add_action("do_push", "push");
}

void close_path()
{
 if( !query("exits/northdown") ) return;
 message("vision","��ʯ����ת����ʯ������ʧ�ˡ�\n",this_object() );
 delete("exits/northdown");
}

int do_push(string arg)
{
 object me;

 me = this_player();
 if(!arg || arg=="")
  {
   write("��Ҫ��ʲô��\n");
   return 1;
  }
 if( arg == "yanshi" || arg == "��ʯ")
  {
   message_vision("$N��������������ʯ����ʯ��Ȼ�ζ���һ�£�¶����һ���򱱵�·��\n", me);
   if(!me->query("m_success/������"))
    {
     me->set("m_success/������",1);
     me->add("score",100);
    }
   if( !query("exits/northdown") )
    {
     set("exits/northdown", __DIR__"gudi1");
     call_out("close_path", 5);
    }
  }
  else write("�㲻������!!\n");
  return 1;       
}