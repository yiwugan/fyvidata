#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
        set_name("��ѩ��÷", ({ "plum tree", "tree" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","��ɫ�����ɲ��֣���������ȴ�����ġ�\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 30000);
                set("base_value", 10);
        }
        set_amount(1);
    ::init_item();
}       
