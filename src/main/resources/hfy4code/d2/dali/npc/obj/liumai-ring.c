//liumai-ring
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIG "六脉戒指" NOR, ({ "liumai-ring"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个翠闪烁着奇异光芒的戒指。\n");
                set("unit", "个");
                set("value", 100000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 5);
                set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
                set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");


        }
      
}