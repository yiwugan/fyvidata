// TIE@FY3
#include <armor.h>
inherit NECK;
#include <ansi.h>
void create()
{
        set_name(HIR"血红丝巾"NOR, ({ "ribbon" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", @LONG
用热血染红的丝巾，虽然有点脏得像抹布，但扯一扯就可以再随风飘扬。
LONG);
                set("material", "stone");
                set("armor_prop/armor", 2);
                set("armor_prop/courage",10);
        }
        ::init_neck();
} 
  
