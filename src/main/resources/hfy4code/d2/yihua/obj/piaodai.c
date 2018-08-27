#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{	string piaod;
        set_name( "[1;31mÎå[1;33m²Ê[1;35mÆ®[1;36m´ø" NOR, ({ "piaodai" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
               set("value", 500000);
                set("material", "skin");
		set("rigidity", 100);
        }
        init_whip(55);
 		set("no_get",1);
		set("no_drop",1);

        set("wield_msg", "$N´ÓÑü¼äÃþ³öÒ»Ìõ$nÎÕÔÚÊÖÖÐ¡£\n");
        set("unwield_msg", "$N½«ÊÖÖÐµÄ$nÊøÔÚÑü¼ä¡£\n");
        setup();
}
void owner_is_killed(object killer)
{	object obj;
	message_vision("\n$N¸îÏÂÈËÍ·£¬´§Èë×Ô¼ºµÄ»³ÖÐ£¡\n\n",killer);
	obj=new("/tongji/obj/tou11");
	obj->move(killer);
}

