 // cloth.c
//
// This is the basic equip for players just login. 
#include <armor.h> 
inherit CLOTH; 
void create()
{
        set_name("������", ({ "robe" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        ::init_cloth();
}     
