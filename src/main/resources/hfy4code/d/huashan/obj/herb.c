 inherit ITEM;
#include <ansi.h>
#include <condition.h>
void create()
{
  set_name(MAG"���̲�"NOR,({"ziyan","ziyan grass"}));
  set("long", 
      "һ��ͨ����̵�С�ݣ���Ҷ�ı���΢΢͸����ɫ�����нⶾ�������壩�Ĺ��ܣ�\n");
  set("value",10000);
  set("unit","��");
} 
void init()
{
  if(this_player()==environment())
  add_action("do_cure", "cure");
} 
int do_cure()
{
        object me;
        me = this_player();
        message_vision("$N�����̲�ϸϸ����������ȥ��\n",me);
        me->clear_condition();
        me->clear_condition_type(NERVE_POISON);
        destruct(this_object());
        return 1;
}       
