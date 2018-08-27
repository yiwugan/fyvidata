// cloth.c
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY "五" + HIR "彩" + HIW "锦衣" NOR, ({ "jin cloth","jinyi" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件五彩斑斓的，用锦缎缝成的衣服,质地高贵，更显出此人的不一般。\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 40);
        }
        
}