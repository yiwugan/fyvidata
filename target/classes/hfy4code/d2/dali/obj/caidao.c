#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("菜刀", ({ "caidao" , "菜刀" }) ); 
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500);
                set("material", "metal");
                set("long", "崭新的菜刀。\n");
                set("wield_msg", "$N拿出一把崭新的$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        ::init_blade(10);
        
}