// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���", ({ "mianju"} ) );
	set_weight(3000);
		set("no_get",1);
		set("no_drop",1);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N������ͷ�������Լ��Ļ��У�\n\n",killer);
	obj=new("/tongji/obj/tou5");
	obj->move(killer);
}
