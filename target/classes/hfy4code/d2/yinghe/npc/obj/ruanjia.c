 // -neon
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name(HIC"��ɫ���"NOR, ({ "ruan jia", "cloth" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ����ɫ����ס�\n");
        set("material", "cloth");
        set("armor_prop/armor", 25);
        set("female_only", 1);
        set("value",4000);
    }
    ::init_cloth();
}     
