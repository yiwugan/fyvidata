 // cloth.c
// 
#include <armor.h> 
inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name("����", ({ "liu cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ɴ֯�ɵĳ���\n");
                set("material", "cloth");
                set("value", 1000);
                set("armor_prop/armor", 3);
        }
        ::init_cloth();
}