inherit ROOM;
// #include <command.h>
#include <ansi.h>
void create()
{
        set("short", "�ͱ�");
        set("long", @LONG
������������ƻ�����Χ֮����.���ǽ����ƻ���
��Χ֮�ڵ��˶��÷����ƻ�����ÿһ��涨.��Ȼ
�������"��".
LONG
        );
        set("outdoors", "yihua");
        set("exits", ([
                "northup"    : "d/yihua/juebi",
        ]));
        set("coor/x",-165);
	set("coor/y",165);
	set("coor/z",30);
        set("objects", ([
                __DIR__"npc/yingke" : 1,              
       ]) );
        setup();
}
void init()
{
   add_action("do_jump", "jump");
}

int do_jump(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "����") 
    {
     write("��Ҫ���ı�������");
     return 0; 
    }
   mlvl = (int)me->query_skill("move",1);
   if(mlvl < 180)
    {
      message_vision("$N�����������˹�ȥ������....\n���ã�����û����������\n", me);
    me->unconcious();
      me->set("sen",(int)me->query("sen")/2);
      me->set("eff_sen",(int)me->query("eff_sen")/2);
      me->set("kee",(int)me->query("kee")/2);
      me->set("eff_kee",(int)me->query("eff_kee")/2);
      me->set("gin",(int)me->query("gin")/2);
      me->set("eff_gin",(int)me->query("eff_gin")/2);
      me->unconcious();
      me->start_busy(4);
      call_out("fliping",4,me);
      me->stop_busy();
    }
   else{
      message_vision("$N�����������˹�ȥ����ֻ���ö��߷����������졣������\n\n", me);
      room = load_object(__DIR__"feiyun");
      message_vision("��ֻ�պ����������ͱڵı��ϣ������ġ�����\n", me);
      me->move(room);
   }
   return 1;
}
int fliping(object me)
{
	if( !me->is_ghost()) {
        me->move("/d/shaolin/neiyuan");
        message_vision("$N˳��ɽ��ˤ��������\n", me);
        me->unconcious();
	}
        return 1;
}
