#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("���Ƽ�", ({ "giant arrow", "arrow" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����͵ļ�ͷ��\n");
                set("value", 1000);
        set("material", "metal");
    }
        ::init_item();
}      
