//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIY "ľ����" NOR, ({ "qipan" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("long", "����һ��ľ�Ƶ����̡�\n");
                set("material", "wood");
        }
        ::init_blade(5);
        
}
