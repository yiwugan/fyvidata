//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW "茶花刀" NOR, ({ "huadao" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 50000);
                set("long", "这是一把锋利的宝刀，刀身上隐约可以看到朵朵茶花。\n");
                set("material", "steel");
                set("wield_msg", "伴随着片片飞花，$N的手里已经多了一把$n！\n");
                set("unwield_msg", "一阵清香过后，$N的$n已无声无息地落入刀鞘。\n");
        }
        ::init_blade(45);
        
}