 // -neon
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name(HIW"���þ�װ"NOR, ({ "white cloth", "cloth" }) );
    set_weight(4000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ����ɫ����Ƥ�����ľ�װ����������ᱣů��\n");
        set("material", "cloth");
        set("bigcloth", 1);
        set("armor_prop/armor", 30);
        set("value",4000);
    }
    ::init_cloth();
}   
