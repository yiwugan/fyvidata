#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY "����"+ HIR"����"NOR, ({ "jiasha" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("value",1000);
        }
        
}