// cloth.c
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY "黄金甲" NOR, ({ "armor","gold armor" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件金黄色的护甲，只有大理一等的侍卫才有资格穿上它。\n");
                set("value", 50000);
                set("material", "cloth");
                set("armor_prop/armor", 40);
        }
        
}