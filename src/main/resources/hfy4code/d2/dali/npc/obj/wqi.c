// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("������", ({ "white piece", "piece" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "��ɫʯͷ����\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set("value", 0);
        set_amount(1000);
        ::init_throwing(1);
        
}
