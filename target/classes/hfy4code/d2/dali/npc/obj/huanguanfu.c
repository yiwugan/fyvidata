// cloth.c
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("�¹ٷ�", ({ "huanguan fu","guanfu" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����̫��ר�õ��·����ʵظ߹�\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        
}