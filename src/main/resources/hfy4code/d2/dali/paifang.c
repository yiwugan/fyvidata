#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY "�Ʒ�" NOR);
        set("long", @LONG
��������һ���Ʒ�֮ǰ���Ʒ��������ĸ���ʴ��֡�ʥ����ȡ���
Ϧ�����ڻ��߹�����������ϣ���̻Իͣ�����ĿΪ֮�š�ǰ����һ��
���������д�š�ʥ�ȹ����������֡�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__ "gnroad2",
  "west" : __DIR__ "yamen4",
]));
       set("objects", ([
       __DIR__"npc/weishi" : 2,
                       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-680);
        set("coor/z",80);
        setup();
//        replace_program(ROOM);
        
}

void init()
{
        add_action("do_open", "open");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "door" || arg == "����")
        {
        me = this_player();
        message_vision("$N�ѹ��Ŵ򿪡�\n", me);
        if( !query("exits/north") ) 
        set("exits/north", __DIR__"shengcigong");
         }
        return 1;
}
int valid_leave(object me, string dir)
{
 object ob;
 string strr1="";

 if(wizardp(me)) return 1;

 if( !userp(me)) return 1;

 if( me->query("class") != "dali" && dir == "north" && ob=present("weishi", this_object()))
   return notify_fail(ob->name() + "�ѳ���һ��ȵ�������ʹ��صأ��Ǵ������˲�����룡��\n");    

 if( me->query("class") == "dali" && (me->query("gongxian") < 5120) && dir == "north" && ob=present("weishi", this_object()))
   return notify_fail(ob->name() + "�Ѱ���һ��˵������Ĺ��β�����ֻ�н������ϲ��ܽ�����ʹ���\n");    

 if( (me->query("class") == "dali") && (me->query("gongxian") > 5120) && dir == "north" && ob=present("weishi", this_object())) 
   {

   ob->ccommand(strr1);

   return 1;
  }
 return 1;
}
