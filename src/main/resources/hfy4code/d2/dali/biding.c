inherit ROOM;
// #include <command.h>
#include <ansi.h>
void create()
{
        set("short", "�ͱڶ�");
        set("long", @LONG
�����ͱڶ��ϵ�һ��ƽ�أ�������һ���ܿ���ѷ죬����һ
�£����������������𣩹�ȥ��
LONG
        );
        set("coor/x",-710);
        set("coor/y",-900);
        set("coor/z",150);
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
   if(!arg || arg != "east") 
    {
     write("��Ҫ���ı�������");
     return 0; 
    }
   mlvl = (int)me->query_skill("move",1);
//   write(mlvl);
   if(mlvl < 200)
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
      room = load_object(__DIR__"biding1");
      message_vision("��ֻ�պ����������ͱڵı��ϣ������ġ�����\n", me);
      me->move(room);
   }
   return 1;
}
int fliping(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"shangu");
        message_vision("$N˳��ɽ��ˤ��������\n", me);
//        me->unconcious();
        }
        return 1;
}