//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW "石棋盘" NOR, ({ "stonepan" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("value", 2000);
                set("long", "这是一块玉石制的棋盘。\n");
                set("material", "stone");
        }
        ::init_blade(10);
        
}