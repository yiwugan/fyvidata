
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "guzi" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ�ž�����͸����������\n");
		set("unit", "��");
		set("no_get",1);
		set("no_drop",1);
		set("value", 100);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(888);
	init_throwing(50);
	setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N������ͷ�������Լ��Ļ��У�\n\n",killer);
	obj=new("/tongji/obj/tou6");
	obj->move(killer);
}
