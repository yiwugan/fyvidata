// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("°×ÔÆ×Ó", ({ "white yun-piece", "yun-piece" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "°×É«ÔÆ×Ó\n");
                set("unit", "ºÐ");
                set("base_unit", "Á£");
                set("base_weight", 1);
                set("base_value", 10);
        }
        set("value", 0);
        set_amount(200);
        ::init_throwing(1);
        
}
