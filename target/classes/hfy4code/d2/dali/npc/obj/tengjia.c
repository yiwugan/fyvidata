// cloth.c
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("滕甲", ({ "teng jia","jia" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件普通的护甲。\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
        
}