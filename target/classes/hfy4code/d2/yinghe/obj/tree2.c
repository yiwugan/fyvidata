#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
        set_name(WHT"������"NOR, ({ "maple tree", "tree" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","����ɫ�����ɻ������֡�\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 10000);
                set("base_value", 10);
        }
        set_amount(1);
    ::init_item();
}      
