//  An example non-weapon type of weapon
#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
	set_name(HIW"铁钩"NOR, ({ "tiegou" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个亮闪闪的铁钩，似乎很锋利。\n");
		set("value", 0);
		set("material", "steel");
		set("no_get",1);
		set("no_drop",1);

	}
	init_ring(50);

	set("wield_msg", "$N从怀中摸出一个$n拿在手中。\n");
	set("unwield_msg", "$N将手上的$n藏入怀中。\n");

// The setup() is required.

	setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N割下人头，揣入自己的怀中！\n\n",killer);
	obj=new("/tongji/obj/tou1");
	obj->move(killer);
}


