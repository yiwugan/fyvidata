// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("面具", ({ "mianju"} ) );
	set_weight(3000);
		set("no_get",1);
		set("no_drop",1);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N割下人头，揣入自己的怀中！\n\n",killer);
	obj=new("/tongji/obj/tou5");
	obj->move(killer);
}
