//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW "ʯ����" NOR, ({ "stonepan" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("long", "����һ����ʯ�Ƶ����̡�\n");
                set("material", "stone");
        }
        ::init_blade(10);
        
}