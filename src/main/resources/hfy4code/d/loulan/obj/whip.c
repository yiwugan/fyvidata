 // rope.c
#include <ansi.h>
#include <weapon.h> 
inherit WHIP; 
void create()
{
        set_name( "虎尾鞭", ({ "whip" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 5000);
                set("material", "skin");
        }
        init_whip(45); 
        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n"); 
}     
