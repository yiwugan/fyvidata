#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("表哥的信", ({ "biaoge xin","xin" }) );
    set_weight(1);
    set("no_shown", 1);
//    set("no_give", 1);
//    set("no_drop", 1);
//        set("prep","in");
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "封");
            set("material", "paper");
            set("long", "一封信，信封上写着：
             语嫣表妹      亲启\n");
          }
    
}