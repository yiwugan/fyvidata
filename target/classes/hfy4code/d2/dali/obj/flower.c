#include <armor.h>

inherit ITEM;
#include <ansi.h>
void create()
{
        string *order=({HIY"��Ʒ�軨" NOR, HIG"һƷ�軨" NOR,
YEL"��Ʒ�軨" NOR,HIW"��Ʒ�軨" NOR,GRN"һ��軨" NOR});
        set_name((order[random(5)]), ({ "tea flower","flower"}) );
        set("pname",this_player()->query("id"));
        set_weight(100000);
        set("value", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        
}
