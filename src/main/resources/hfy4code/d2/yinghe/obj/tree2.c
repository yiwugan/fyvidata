#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
        set_name(WHT"不凋金枫"NOR, ({ "maple tree", "tree" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","银灰色的树干滑不留手。\n");
                set("unit", "捆");
                set("base_unit", "根");
                set("base_weight", 10000);
                set("base_value", 10);
        }
        set_amount(1);
    ::init_item();
}      
