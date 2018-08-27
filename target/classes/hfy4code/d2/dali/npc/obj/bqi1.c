// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("上等黑云子", ({ "black yunpiece", "yunpiece" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "上等的黑色云子\n");
                set("unit", "盒");
                set("base_unit", "粒");
                set("base_weight", 1);
                set("base_value", 500);
        }
        set("value", 1000);
        set_amount(200);
        ::init_throwing(1);
        
}