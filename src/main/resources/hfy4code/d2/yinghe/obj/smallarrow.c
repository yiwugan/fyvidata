#include <ansi.h>
#include <weapon.h>
inherit THROWING; 
void create()
{
        set_name("碎玉箭", ({ "small arrow", "arrow" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个小巧的箭头，短短的箭杆上镶嵌有一小段玉石。\n");
                set("unit", "捆");
                set("base_value", 1000);
                set("base_weight", 800);
        set("base_unit", "个");
        set("material", "metal");
    }
        set_amount(10);
        ::init_throwing(10);
}    
