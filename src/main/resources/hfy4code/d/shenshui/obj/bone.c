 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("白骨", ({ "白骨" , "baigu","bone"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "堆");
                set("long", "一堆白骨，上面的血迹已经乾枯，表面已深受风沙的侵蚀。\n");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }      
