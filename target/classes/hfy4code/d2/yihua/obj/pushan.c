
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name( "����" , ({ "pushan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱���µ�����\n");
		set("no_get",1);
		set("no_drop",1);
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N��$n���������������¡�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	init_dagger(35);
	setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N������ͷ�������Լ��Ļ��У�\n\n",killer);
	obj=new("/tongji/obj/tou9");
	obj->move(killer);
}
