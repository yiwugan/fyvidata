//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIR "����" NOR,({"xiushu"}));
 set_weight(10);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIR "һ����ʹ��Ϸ�����������ż�����顣\n"NOR);
    set("unit","��");
    set("value", 100000000);
   }
}

void init()
{
 add_action("eat_guo","xie");
}

int eat_guo(string arg)
{
 if ( arg == "xiushu")
  {
   message_vision(HIR"$Nд����һ�����飬�����������ڵ���ż��\n"NOR,this_player());
   this_player()->delete("marry");
   this_player()->add("divorced",-1);
   if (this_player()->query("divorced") < 0) 
    {
     this_player()->delete("divorced");
    }
   if(this_player()->query("score") >= 5000) this_player()->add("score",-5000);
    else this_player()->set("score",0);
   destruct(this_object());
   return 1;
  }
 return 0; 
}