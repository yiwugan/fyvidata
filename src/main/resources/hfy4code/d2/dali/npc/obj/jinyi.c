// cloth.c
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY "��" + HIR "��" + HIW "����" NOR, ({ "jin cloth","jinyi" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ʰ�쵵ģ��ý��з�ɵ��·�,�ʵظ߹󣬸��Գ����˵Ĳ�һ�㡣\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 40);
        }
        
}