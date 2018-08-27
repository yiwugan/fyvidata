// sichou_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIC "˿��"+ HIG "����" NOR, ({ "sichou-cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 4000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 10);
        }
        ::init_cloth();

}