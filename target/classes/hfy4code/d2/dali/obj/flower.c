#include <armor.h>

inherit ITEM;
#include <ansi.h>
void create()
{
        string *order=({HIY"极品茶花" NOR, HIG"一品茶花" NOR,
YEL"二品茶花" NOR,HIW"三品茶花" NOR,GRN"一般茶花" NOR});
        set_name((order[random(5)]), ({ "tea flower","flower"}) );
        set("pname",this_player()->query("id"));
        set_weight(100000);
        set("value", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盆");
        }
        
}
