#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(WHT"合梦明珠"NOR, ({ "pearl" , "合梦明珠", "dream pearl"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个荧白的色珍珠。\n");
                set("value", 10000);
        }
    ::init_item();
}   
