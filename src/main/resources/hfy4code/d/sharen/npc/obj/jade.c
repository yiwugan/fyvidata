#include <ansi.h>
#include <armor.h> 
inherit NECK; 
void create()
{
        set_name(GRN"无极八卦玉佩"NOR, ({"jade", "yu pei"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块乾坤八卦状的蓝田古玉，玉佩后面刻了个『俞』字。\n");
                set("unit", "个");
                set("value", 10000);
                set("armor_prop/armor", 2);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一块$n别在腰带上。\n");
                set("unwield_msg", "$N轻轻地把$n从腰带上除了下来。\n");
        }
        ::init_neck();
}   
