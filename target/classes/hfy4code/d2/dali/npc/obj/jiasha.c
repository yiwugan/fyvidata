#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY "ÍÅÁú"+ HIR"ôÂôÄ"NOR, ({ "jiasha" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("value",1000);
        }
        
}