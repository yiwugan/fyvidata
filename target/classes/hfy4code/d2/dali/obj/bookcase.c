//XXDER
#include <ansi.h>
inherit ITEM;
void create()
{
   object item1;
   set_name("���", ({ "bookcase" , "���", "book case" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);
   set("no_clean_up",1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "��");
      set("long", "����һ������ܡ�\n");
      set("value", 1);
   }
}
int is_container() { return 1; }

void init()
{
        if(this_player()==environment())
                 add_action("do_open","open");
}
int do_open(string arg)
{
        object          me, ob;
        if( !arg || arg != "bookcase" )
                return notify_fail("��Ҫ��ʲô��\n");
        me = this_player();
        ob = this_object();
        message_vision("$N����֨��һ������$n���ˡ�����\n", me, ob);
                ob->set("closed",0);
        return 1;
}

int is_closed()
{
        return ((int) this_object()->query("closed"));
}