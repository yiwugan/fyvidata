// cloth.c
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY "�ƽ��" NOR, ({ "armor","gold armor" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ɫ�Ļ��ף�ֻ�д���һ�ȵ����������ʸ�������\n");
                set("value", 50000);
                set("material", "cloth");
                set("armor_prop/armor", 40);
        }
        
}