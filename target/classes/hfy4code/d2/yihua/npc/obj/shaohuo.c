//  An example non-weapon type of weapon

#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("烧火棍", ({ "shaohuo" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一截焦黑的烧火棍\n");
		set("value", 0);
		set("material", "steel");
		set("no_get",1);
		set("no_drop",1);

	}
	init_staff(30);

        set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");

// The setup() is required.

	setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N割下人头，揣入自己的怀中！\n\n",killer);
	obj=new("/tongji/obj/tou4");
	obj->move(killer);
}

