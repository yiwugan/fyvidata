inherit ROOM;

void init();
int do_zou(string);

void create()
{
  set("short","����");
  set("long",@LONG
���㶫����һ�����ڣ����¿�ȥ�������ƣ����������Ǹ���԰�����
���޷�����ȵס�������ȥ(east)ʲôҲ���������Ա���һ��ʯ��(bei)��
LONG
     );
  set("outdoors", "yihua");
  set("exits",([
      "southdown" : "/d/yihua/qiaobi",
      "northdown" : "/d/yihua/xiaojing",
     ]));
  set("item_desc",([
      "bei" : "���ƻ�������ֹ���˽���,Υ�ߺ���Ը���\n" ,
      "east" : "����û���κ�·�����벻ͨ����(jump)��ȥ��\n" ,
     ]));
        set("coor/x",-170);
        set("coor/y",170);
        set("coor/z",40);
 setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me=this_player(), room;

        if(!arg || arg!="east")
                return notify_fail("������벻ͨ��\n");

        if(!( room = find_object(__DIR__"xiaojin")) )
                room = load_object(__DIR__"xiaojin");

        if(!objectp(room))
                return notify_fail("ERROR:not found 'xiaojin.c' \n");
        message_vision("$N˫��һ�գ���Ȼ������ȥ��\n",me);
//       ��message("vision","��ֻ��һ����Ӱ���������\n", room);
        me->move(room);
        return 1;
}