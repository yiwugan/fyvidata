
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("算盘"NOR, ({ "suanpan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "把");
 		set("no_get",1);
		set("no_drop",1);
           set("material", "gold");
            set("long", "一把纯金打造算盘。\n");
		set("value", 1);
	}
	setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N割下人头，揣入自己的怀中！\n\n",killer);
	obj=new("/tongji/obj/tou8");
	obj->move(killer);
}

