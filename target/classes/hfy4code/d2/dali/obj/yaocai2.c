#include <armor.h>

inherit ITEM;
#include <ansi.h>
void create()
{
        string *order=({HIY"千年人参" NOR, YEL"何首乌精" NOR,
HIW"珍贵北芪" NOR,HIG"成型淮山" NOR,GRN"一般树根" NOR,GRN"一般药材" NOR,GRN"一般杂草" NOR});
        set_name((order[random(7)]), ({ "yao cai","yao"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
        }
        
}