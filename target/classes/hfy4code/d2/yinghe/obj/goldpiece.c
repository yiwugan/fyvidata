 // gold.c
#include <ansi.h>
inherit MONEY; 
void create()
{
        set_name(HIY"���"NOR, ({"gold piece", "gold"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�Ƴγε�����˼��˰��Ľ��ӣ����������ӣ�\n");
                set("unit", "Щ");
                set("base_value", 10000 );
                set("base_unit", "��");
                set("base_weight", 37);
        }
        set_amount(1);
}       
