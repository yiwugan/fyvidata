// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("ºÚÔÆ×Ó", ({ "black yun-piece", "yun-piece" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"ºÚÉ«ÔÆ×Ó\n");
		set("unit", "ºÐ");
		set("base_unit", "Á£");
		set("base_weight", 1);
                set("base_value", 1);
	}
        set("value", 0);
	set_amount(200);
	::init_throwing(1);
	
}
