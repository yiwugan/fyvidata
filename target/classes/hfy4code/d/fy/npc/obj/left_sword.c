 // sword_long.c
#include <weapon.h> 
inherit SWORD; 
void create()
{
        set_name("左手剑", ({ "left-sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把只适合左撇子用的长剑，剑身轻薄\n");
                set("value", 80);
                set("material", "steel");
                set("wield_msg", "$N双手一分，拿出一双$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        } 
        ::init_hammer(155);
}       
