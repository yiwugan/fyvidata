// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("团龙官服", ({ "guanfu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是大理城王爷的官服。\n");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        
}