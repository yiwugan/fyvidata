 // pearl.c
#include <weapon.h> 
#include <ansi.h>
inherit THROWING; 
void create()
{
        set_name(HIY"金狼牙"NOR, ({ "wolf tooth", "tooth" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "一颗纯金打造的狼牙，坚硬且尖锐。在牙面上刻了个蝇头小字「萧」。\n");
                set("unit", "颗");
                set("base_unit", "颗");
                set("base_weight", 1);
                //set("for_create_weapon",1);
                set("base_value", 1);
                set("stone",1);
        }
        set_amount(1);
        ::init_throwing(50);
}   
