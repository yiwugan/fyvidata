#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(HIW"白银甲"NOR, ({ "silver chainarmor","chainarmor" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "silver");
                set("long", "一件闪闪发光的白银盔甲。\n");
                set("value", 20000);
                set("armor_prop/armor", 60);
        }
        ::init_armor();
} 
