//转档玩家专用，其他用途不可以，不是admin不能clone 和co copy
//违者处分
#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIR "转档丹" NOR,({"zhuandang-dan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "一颗使你能到这个风云转档得神丹。\n"NOR);
    set("unit","颗");
        set("value", 1000);
   }
}

void init()
{
 add_action("eat_guo","eat");
}

int eat_guo(string arg)
{
         object me;
        me = this_player();
                if (this_player()->query("eatzddan")>0 ) return notify_fail("你已经吃过了，不可以再吃了!\n");
 if ( arg == "zhuandang-dan")
  {
   message_vision(HIC"$N小心翼翼的服下一颗转档丹，一股清香直冲面门。\n"NOR,this_player());
   this_player()->set("combat_exp",120000);
     this_player()->set("int",30);
   this_player()->set("str",30);
   this_player()->set("spi",20);
   this_player()->set("con",30);
  this_player()->set("dur",30);
   this_player()->set("fle",20);
   this_player()->set("agi",30);
   this_player()->set("max_force",800);
   this_player()->set("max_atman",225);
   this_player()->set_skill("force",150);
   this_player()->set_skill("iron-cloth",100);
   this_player()->set_skill("jin-gang",50);
   this_player()->set_skill("magic",51);
   this_player()->set("max_mana",225);
   this_player()->set_skill("move",150);
   this_player()->set_skill("parry",150);
   this_player()->set_skill("dodge",150);
   this_player()->set_skill("essencemagic",61);
   this_player()->set("mud_age",1100);
   this_player()->set_skill("unarmed",150);
   this_player()->set_skill("yoga",150);
 //  this_player()->set_skill("literate",150);
   this_player()->add("potential",50000);
this_player()->add("eatzddan",1);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
//转档玩家专用，其他用途不可以，不是admin不能clone 和co copy
//违者处分

