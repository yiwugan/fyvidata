// cloth.c
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("宦官服", ({ "huanguan fu","guanfu" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是太监专用的衣服，质地高贵。\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        
}