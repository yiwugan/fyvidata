// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("�ϵȰ�����", ({ "white yunpiece", "yunpiece" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "�ϵȵİ�ɫ����\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1);
                set("base_value", 500);
        }
        set("value", 0);
        set_amount(200);
        ::init_throwing(1);
        
}
