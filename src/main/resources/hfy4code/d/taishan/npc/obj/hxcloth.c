//by xiaolang
#include <armor.h> 
#include <ansi.h>
inherit CLOTH; 
void create()
{
        set_name(BLU"洗的发白的蓝布衣裳"NOR, ({ "bluecloth", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 80);
        set("value", 3000);
        set("long", "一件普通的蓝布衣裳，已经洗的发白了。\n");
        }
        ::init_cloth();
}       
