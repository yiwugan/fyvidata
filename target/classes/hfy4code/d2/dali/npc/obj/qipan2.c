//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(BLU "������" NOR, ({ "tiepan" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("long", "����һ�����Ƶ����̡�\n");
                set("material", "steel");
        }
        ::init_blade(15);
        
}