
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name( "蒲扇" , ({ "pushan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当精致的蒲扇\n");
		set("no_get",1);
		set("no_drop",1);
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N把$n握在手中扇了两下。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	init_dagger(35);
	setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N割下人头，揣入自己的怀中！\n\n",killer);
	obj=new("/tongji/obj/tou9");
	obj->move(killer);
}
