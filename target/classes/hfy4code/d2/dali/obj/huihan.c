#include <armor.h>

inherit ITEM;
#include <ansi.h>
void create()
{
//        string *order=({"南宫十一郎","南宫十三郎"});
        set_name(("回函"), ({ "huihan"}) );
        set("fromname",this_player()->query("name"));
        set_weight(100000);
        set("value", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
        }
      
}

