// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("龙袍", ({ "longpao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是大理皇帝的龙袍。\n");
                set("value", 100000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        
}