#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{	string piaod;
        set_name( "[1;31m��[1;33m��[1;35mƮ[1;36m��" NOR, ({ "piaodai" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
               set("value", 500000);
                set("material", "skin");
		set("rigidity", 100);
        }
        init_whip(55);
 		set("no_get",1);
		set("no_drop",1);

        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N������ͷ�������Լ��Ļ��У�\n\n",killer);
	obj=new("/tongji/obj/tou11");
	obj->move(killer);
}

