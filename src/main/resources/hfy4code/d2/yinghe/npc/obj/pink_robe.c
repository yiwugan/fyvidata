#include <armor.h>
#include <ansi.h>
inherit CLOTH; 
void create()
{
        set_name("�������", ({ "pink robe","robe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ķ�ɫ���ۣ���ӯ�Ử����ͬ���е��һ���
һ��ǳ���˿��ǡ���ô��ػ������䡣\n");
                set("material", "cloth");
                set("armor_prop/armor", 5);
                set("armor_prop/personality", 5);
        }
        ::init_cloth();
}     
