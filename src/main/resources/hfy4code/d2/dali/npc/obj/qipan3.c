//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIB "��������" NOR, ({ "hantiepan" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ǧ�꺮���Ƶ����̡�\n");

                set("value", 5000000);
                set("rigidity",2000);   
                set("material", "steel");
                set("max_enchant",7);
                set("for_create_weapon",2);
        }
        ::init_blade(25);
        
}