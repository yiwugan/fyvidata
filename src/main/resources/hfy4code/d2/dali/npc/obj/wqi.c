// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("白棋子", ({ "white piece", "piece" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "白色石头棋子\n");
                set("unit", "盒");
                set("base_unit", "粒");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set("value", 0);
        set_amount(1000);
        ::init_throwing(1);
        
}
