#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"����"NOR, ({"black seed", "seed"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�ź�ɫ�����ӡ�\n");
                set("lore",1);
                set("unit", "��");
                set("value", 1);
        }
    ::init_item();
}   
