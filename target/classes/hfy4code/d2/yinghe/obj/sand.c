#include <ansi.h>
inherit ITEM; 
void create()
{
    set_name(YEL"ڤɳ"NOR, ({ "hel sand", "ming sand" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һЩ�������ڵ�ϸɳ��\n");
        set("unit", "Щ");
        set("value", 5); 
    }
    ::init_item();
}  
