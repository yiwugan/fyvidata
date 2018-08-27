// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("上等白云子", ({ "white yunpiece", "yunpiece" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "上等的白色云子\n");
                set("unit", "盒");
                set("base_unit", "粒");
                set("base_weight", 1);
                set("base_value", 500);
        }
        set("value", 0);
        set_amount(200);
        ::init_throwing(1);
        
}
