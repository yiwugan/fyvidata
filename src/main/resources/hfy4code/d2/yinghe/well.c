 // Room: rope_net.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG); 
        set("indoors", "yinghe");
        setup();
} 
void init(){
        add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
   object me, room; 
   me = this_player();
   if(me->is_busy() || me->is_fighting())
                return notify_fail("������û�գ�\n");
   switch (random(3)) {
   case 0:
      message_vision("$N�ֽŲ��õ���������������һ�룬һʧ����ˤ��������\n", me);
      me->receive_damage("gin",20);
                me->start_busy(3);
      break;
   case 1:
      message_vision("$N�ֽŲ��õ����������ۿ��쵽�����ˣ����һʧ����ˤ��������\n", me);
      me->receive_damage("gin",40);
                me->start_busy(3);
      break;
   case 2:
      if(!arg || arg != "��" && arg != "up" ) return 0;
      room = find_object(__DIR__"woodroad");
      if(!objectp(room)) room=load_object(__DIR__"woodroad");
      me->move(room);
      message_vision("$N����ʪ���ܵش�ˮ��������������\n", me);
      break;
   }
   return 1;
}
