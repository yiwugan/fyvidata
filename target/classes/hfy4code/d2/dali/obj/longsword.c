//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG "游龙剑" NOR, ({ "longsword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500);
                set("long", "这是一把锋利的宝剑，剑身上刻着一条威猛的游龙。\n");
                set("material", "steel");
                set("wield_msg", "一道青光闪过，$N的手里已经多了一把$n！\n");
                set("unwield_msg", "$N手中的$n无声无息地落入龙纹剑鞘。\n");
        }
        ::init_sword(45);
        
}