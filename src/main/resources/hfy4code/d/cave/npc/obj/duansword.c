 // sword.c : an example weapon
#include <weapon.h> 
inherit SWORD; 
void create()
{
    set_name("丧门剑", ({ "sangmen sword","sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long", "剑光闪着惨青色的光，映人双眼。\n");
        set("value", 20000);
                set("material", "steel");
        }
    ::init_sword(45); 
// These properties are optional, if you don't set them, it will use the
// default values. 
        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");  
}    
